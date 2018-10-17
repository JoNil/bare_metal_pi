#include "gpio.h"
#include "reload.h"
#include "types.h"

#define UART0_DR ((volatile unsigned int *)(MMIO_BASE + 0x00201000))
#define UART0_FR ((volatile unsigned int *)(MMIO_BASE + 0x00201018))

__attribute__((section (".text.reload")))
static void reload_uart_send(unsigned int c)
{
    do { asm volatile("nop"); } while (*UART0_FR & 0x20);
 
    *UART0_DR = c;
}

__attribute__((section (".text.reload")))
static char reload_uart_getc()
{
    do { asm volatile("nop"); } while (*UART0_FR & 0x10);

    return (char)(*UART0_DR);
}

__attribute__((section (".text.reload")))
static void reload_uart_puts(const char * s)
{
    while (*s) {
        reload_uart_send(*s++);
    }
}

__attribute__((section (".text.reload")))
void reload_initial(const char * date)
{
    reload_uart_send('I');
    reload_uart_send('n');
    reload_uart_send('i');
    reload_uart_send('t');
    reload_uart_send(' ');

    reload_uart_puts(date);

    reload_uart_send('\n');

    for (;;) {
        reload_uart_send(reload_uart_getc());       
    }
}