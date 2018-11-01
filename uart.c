#include "gpio.h"
#include "mbox.h"
#include "str.h"
#include "types.h"
#include "uart.h"

// PL011 UART registers
#define UART0_DR        ((volatile u32 *)(MMIO_BASE + 0x00201000))
#define UART0_FR        ((volatile u32 *)(MMIO_BASE + 0x00201018))
#define UART0_IBRD      ((volatile u32 *)(MMIO_BASE + 0x00201024))
#define UART0_FBRD      ((volatile u32 *)(MMIO_BASE + 0x00201028))
#define UART0_LCRH      ((volatile u32 *)(MMIO_BASE + 0x0020102C))
#define UART0_CR        ((volatile u32 *)(MMIO_BASE + 0x00201030))
#define UART0_IMSC      ((volatile u32 *)(MMIO_BASE + 0x00201038))
#define UART0_ICR       ((volatile u32 *)(MMIO_BASE + 0x00201044))

void uart_init(void)
{
    // Set baud rate and characteristics (115200 8N1) and map to GPIO

    register unsigned int r;
    
    *UART0_CR = 0;         // turn off UART0

    // Set up clock for consistent divisor values
    mbox[0] = 8*4;
    mbox[1] = MBOX_REQUEST;
   
    mbox[2] = MBOX_TAG_SET_CLOCK_RATE;
    mbox[3] = 12;
    mbox[4] = 8;
    mbox[5] = CLK_UART_ID;
    mbox[6] = 4 * 1000 * 1000;

    mbox[7] = MBOX_TAG_LAST;

    mbox_call(MBOX_CH_PROP);

    // Map UART0 to GPIO pins
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

char uart_getc(void)
{
    do { asm volatile("nop"); } while (*UART0_FR & 0x10);

    return (char)(*UART0_DR);
}

void uart_putc(unsigned int c)
{
    do { asm volatile("nop"); } while (*UART0_FR & 0x20);
    
    *UART0_DR = c;
}

void uart_puts(const char * s)
{
    while (*s) {
        uart_putc(*s++);
    }
}

void uart_buffer(u8 * data, i32 size)
{
    for (i32 i = 0; i < size; ++i) {
        uart_hex_u8(data[i]);
        uart_putc(' ');
    }

    uart_putc('\n');
}

void uart_hex_u32(u32 d) {
    unsigned int n = 0;
    for (int c = 28; c >= 0; c -= 4) {
        // Get highest tetrad
        n = (d >> c) & 0xF;
        // 0-9 => '0'-'9', 10-15 => 'A'-'F'
        n += n > 9 ? 0x37 : 0x30;
        uart_putc(n);
    }
}

void uart_hex_u8(u8 d) {
    unsigned int n = 0;
    for (int c = 4; c >= 0; c -= 4) {
        // Get highest tetrad
        n = (d >> c) & 0xF;
        // 0-9 => '0'-'9', 10-15 => 'A'-'F'
        n += n > 9 ? 0x37 : 0x30;
        uart_putc(n);
    }
}

void uart_i32(i32 d) {
    char buffer[32] = {};
    i32_to_string(buffer, sizeof(buffer), d);
    uart_puts(buffer);
}

