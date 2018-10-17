#include "gpio.h"
#include "mbox.h"

// PL011 UART registers
#define UART0_DR        ((volatile unsigned int *)(MMIO_BASE + 0x00201000))
#define UART0_FR        ((volatile unsigned int *)(MMIO_BASE + 0x00201018))
#define UART0_IBRD      ((volatile unsigned int *)(MMIO_BASE + 0x00201024))
#define UART0_FBRD      ((volatile unsigned int *)(MMIO_BASE + 0x00201028))
#define UART0_LCRH      ((volatile unsigned int *)(MMIO_BASE + 0x0020102C))
#define UART0_CR        ((volatile unsigned int *)(MMIO_BASE + 0x00201030))
#define UART0_IMSC      ((volatile unsigned int *)(MMIO_BASE + 0x00201038))
#define UART0_ICR       ((volatile unsigned int *)(MMIO_BASE + 0x00201044))

void uart_init()
{
    // Set baud rate and characteristics (115200 8N1) and map to GPIO

    register unsigned int r;
    
    *UART0_CR = 0;         // turn off UART0

    // Set up clock for consistent divisor values
    mbox[0] = 8*4;
    mbox[1] = MBOX_REQUEST;
    mbox[2] = MBOX_TAG_SETCLKRATE; // set clock rate
    mbox[3] = 12;
    mbox[4] = 8;
    mbox[5] = 2;           // UART clock
    mbox[6] = 4000000;     // 4Mhz
    mbox[7] = MBOX_TAG_LAST;
    mbox_call(MBOX_CH_PROP);

    // map UART0 to GPIO pins
    r = *GPFSEL1;
    r &= ~((7 << 12) | (7 << 15)); // gpio14, gpio15
    r |= (4 << 12) | (4 << 15);    // alt0
    *GPFSEL1 = r;
    *GPPUD = 0;            // enable pins 14 and 15
    r = 150; while (r--) { asm volatile("nop"); }
    *GPPUDCLK0 = (1 << 14) | (1 << 15);
    r = 150; while (r--) { asm volatile("nop"); }
    *GPPUDCLK0 = 0;        // flush GPIO setup

    *UART0_ICR = 0x7FF;    // clear interrupts
    *UART0_IBRD = 2;       // 115200 baud
    *UART0_FBRD = 0xB;
    *UART0_LCRH = 0b11 << 5; // 8n1
    *UART0_CR = 0x301;     // enable Tx, Rx, FIFO
}

void uart_send(unsigned int c)
{
    do { asm volatile("nop"); } while (*UART0_FR & 0x20);
    
    *UART0_DR = c;
}

char uart_getc()
{
    do { asm volatile("nop"); } while (*UART0_FR & 0x10);

    return (char)(*UART0_DR);
}

void uart_puts(const char * s)
{
    while (*s) {
        uart_send(*s++);
    }
}

void uart_hex(unsigned int d) {
    unsigned int n = 0;
    for (int c = 28; c >= 0; c -= 4) {
        // Get highest tetrad
        n = (d >> c) & 0xF;

        // 0-9 => '0'-'9', 10-15 => 'A'-'F'
        n += n > 9 ? 0x37 : 0x30;
        uart_send(n);
    }
}
