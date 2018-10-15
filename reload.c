#include "gpio.h"
#include "reload.h"
#include "types.h"

#define UART0_DR ((volatile unsigned int *)(MMIO_BASE + 0x00201000))
#define UART0_FR ((volatile unsigned int *)(MMIO_BASE + 0x00201018))

__attribute__((section (".text.reload")))
static void reload_uart_send(unsigned int c)
{
    // Wait until we can send
    do { asm volatile("nop"); } while (*UART0_FR & 0x20);
    // Write the character to the buffer
    *UART0_DR = c;
}

__attribute__((section (".text.reload")))
static char reload_uart_getc()
{
    char r;
    // Wait until something is in the buffer
    do { asm volatile("nop"); } while (*UART0_FR & 0x10);
    // read it and return
    r = (char)(*UART0_DR);
    // convert carrige return to newline
    return r == '\r' ? '\n' : r;
}

__attribute__((section (".text.reload")))
void reload_initial(void)
{

    reload_uart_send('R');
    reload_uart_send('I');
    reload_uart_send('n');

    for (;;) {
        reload_uart_send(reload_uart_getc());       
    }
}