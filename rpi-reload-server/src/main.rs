extern crate byteorder;
extern crate serialport;

use byteorder::{LittleEndian, WriteBytesExt};
use std::error;
use std::fs::read;
use std::io::{BufReader, BufWriter, BufRead, ErrorKind};
use std::time::Duration;

enum Action {
    None,
    SendKernal,
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
    
    let sp = serialport::open_with_settings("COM3", &s)?;

    let mut reader = BufReader::new(sp.try_clone()?;
    let mut writer = BufWriter::new(sp.try_clone()?)

    loop {
        let mut line = String::new();

        let mut action = Action::None;

        match port.read_line(&mut line) {
            Ok(_) => {

                let lt = line.trim();

                println!("{}", lt),

                if lt.starts_with("Init") {
                    action = Action::SendKernal;
                }
            }
            Err(ref e) if e.kind() == ErrorKind::TimedOut => (),
            Err(e) => println!("{:?}", e),
        }

        match action {
            None => (),
            SendKernal => {
                let kernal = fs.read("../kernel8.img")?

                
                port.write_u32::<LittleEndian>(kernal.size())?;
                port.write(kernal)?;
            }
        }
    }
}

