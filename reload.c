#include "gpio.h"
#include "reload.h"
#include "types.h"

#define UART0_DR ((volatile unsigned int *)(MMIO_BASE + 0x00201000))
#define UART0_FR ((volatile unsigned int *)(MMIO_BASE + 0x00201018))

extern const u8 _reload_start;
extern const u8 _reload_end;

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

    u8 * curret_address = (u8 *)0x80000;

    u32 size = 0;

    {
        u8 b1 = reload_uart_getc();
        reload_uart_send(b1);

        u8 b2 = reload_uart_getc();
        reload_uart_send(b2);

        u8 b3 = reload_uart_getc();
        reload_uart_send(b3);

        u8 b4 = reload_uart_getc();
        reload_uart_send(b4);

        size = ((u32)b4 << 24) | ((u32)b3 << 16) | ((u32)b2 << 8) | (u32)b1;
    }

    if (size == 0) {
        return;
    }

    const u8 * reload_start = &_reload_start;
    const u8 * reload_end = &_reload_end;

    for (u32 i = 0; i < size; ++i) {

        u8 byte = reload_uart_getc();
        reload_uart_send(byte);

        if (curret_address < reload_start || curret_address > reload_end) {
            *curret_address = byte;
        }

        curret_address++;
    }

    // Restore arguments and jump to the new kernel.
    asm volatile (

        // Invalidate i cache
        "ic iallu;"

        "mov x0, x10;"
        "mov x1, x11;"
        "mov x2, x12;"
        "mov x3, x13;"
        // We must force an absolute address to branch to
        "mov x30, 0x80000; ret"
    );
}