extern crate byteorder;
extern crate chrono;
extern crate hexdump;
extern crate serialport;

use byteorder::{LittleEndian, ReadBytesExt, WriteBytesExt};
use chrono::{offset::Local, offset::TimeZone};
use std::error;
use std::fs;
use std::io::{BufRead, BufReader, BufWriter, ErrorKind, Read, Write};
use std::time::Duration;

use std::io::Cursor;

enum Action {
    None,
    SendKernal,
    SendZeroSize,
}

fn main() -> Result<(), Box<error::Error>> {
    let s = serialport::SerialPortSettings {
        baud_rate: 115200,
        data_bits: serialport::DataBits::Eight,
        flow_control: serialport::FlowControl::None,
        parity: serialport::Parity::None,
        stop_bits: serialport::StopBits::One,
        timeout: Duration::from_millis(1),
    };

    let sp = {
        let mut sp = None;

        for i in 1..=9 {
            let port = format!("COM{}", i);

            match serialport::open_with_settings(&port, &s) {
                Ok(s) => {
                    println!("Using {}", port);
                    sp = Some(s);
                    break;
                }
                Err(_) => {}
            }
        }

        if let Some(s) = sp {
            s
        } else {
            panic!("Did not find a device");
        }
    };

    let mut reader = BufReader::new(sp.try_clone()?);
    let mut writer = BufWriter::new(sp.try_clone()?);

    loop {
        let mut line = String::new();

        let mut action = Action::None;

        match reader.read_line(&mut line) {
            Ok(_) => {
                let lt = line.trim();

                println!("{}", lt);

                if lt.starts_with("Init") {
                    let build_date_file = fs::read_to_string("../build_date.h")?;

                    let build_date = Local
                        .datetime_from_str(
                            build_date_file
                                .lines()
                                .filter(|s| s.contains("#define BUILD_DATE"))
                                .next()
                                .unwrap()
                                .split("BUILD_DATE")
                                .nth(1)
                                .unwrap()
                                .trim()
                                .trim_matches('\"'),
                            "%Y-%m-%d_%H:%M:%S",
                        ).unwrap();

                    let maybe_rpi_build_date = lt.split(" ").nth(1).and_then(|line_date| {
                        Local.datetime_from_str(line_date, "%Y-%m-%d_%H:%M:%S").ok()
                    });

                    let should_upload = if let Some(rpi_build_date) = maybe_rpi_build_date {
                        build_date > rpi_build_date
                    } else {
                        false
                    };

                    if should_upload {
                        action = Action::SendKernal;
                    } else {
                        action = Action::SendZeroSize;
                    }
                }
            }
            Err(ref e) if e.kind() == ErrorKind::TimedOut => (),
            Err(e) => println!("{:?}", e),
        }

        match action {
            Action::None => (),
            Action::SendKernal => {
                let kernal = fs::read("../kernel8.img")?;

                writer.write_u32::<LittleEndian>(kernal.len() as u32)?;
                writer.flush()?;

                {
                    let mut bytes_read = 0;

                    let mut buffer = vec![0u8; 4];

                    while bytes_read < buffer.len() {
                        match reader.read(&mut buffer[bytes_read..]) {
                            Ok(amount) => {
                                bytes_read += amount;
                            }
                            Err(ref e) if e.kind() == ErrorKind::TimedOut => (),
                            Err(e) => println!("{:?}", e),
                        }
                    }

                    let mut c = Cursor::new(&buffer);

                    assert!(c.read_u32::<LittleEndian>()? == kernal.len() as u32);
                }

                for chunk in kernal.chunks(512) {
                    writer.write_all(&chunk)?;
                    writer.flush()?;

                    let mut bytes_read = 0;

                    let mut buffer = vec![0u8; chunk.len()];

                    while bytes_read < buffer.len() {
                        match reader.read(&mut buffer[bytes_read..]) {
                            Ok(amount) => {
                                bytes_read += amount;
                            }
                            Err(ref e) if e.kind() == ErrorKind::TimedOut => (),
                            Err(e) => println!("{:?}", e),
                        }
                    }

                    assert!(chunk == &buffer[..]);
                }
            }
            Action::SendZeroSize => {
                writer.write_u32::<LittleEndian>(0 as u32)?;
                writer.flush()?;

                {
                    let mut bytes_read = 0;

                    let mut buffer = vec![0u8; 4];

                    while bytes_read < buffer.len() {
                        match reader.read(&mut buffer[bytes_read..]) {
                            Ok(amount) => {
                                bytes_read += amount;
                            }
                            Err(ref e) if e.kind() == ErrorKind::TimedOut => (),
                            Err(e) => println!("{:?}", e),
                        }
                    }

                    let mut c = Cursor::new(&buffer);

                    assert!(c.read_u32::<LittleEndian>()? == 0);
                }
            }
        }
    }
}
