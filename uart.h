#pragma once

#include "types.h"

void uart_init(void);
char uart_getc(void);
void uart_putc(u32 c);
void uart_puts(const char * s);
void uart_buffer(u8 * data, i32 size);
void uart_hex_u32(u32 d);
void uart_hex_u8(u8 d);
void uart_i32(i32 d);
