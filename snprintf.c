#include "snprintf.h"
#include "types.h"
#include "uart.h"

static u32 strlen(const char *s)
{
    u32 len = 0;
    while (s[len] != '\0') len++;
    return len;
}

static u32 itoa(i32 value, u32 radix, u32 uppercase, u32 unsig, char * buffer, u32 zero_pad)
{
    char * pbuffer = buffer;
    int negative = 0;

    if (radix > 16) {
        return 0;
    }

    if (value < 0 && !unsig) {
        negative = 1;
        value = -value;
    }

    do {
        i32 digit = value % radix;
        *(pbuffer++) = (digit < 10 ? '0' + digit : (uppercase ? 'A' : 'a') + digit - 10);
        value /= radix;
    } while (value > 0);

    for (i32 i = (pbuffer - buffer); i < zero_pad; i++) {
        *(pbuffer++) = '0';
    }

    if (negative) {
        *(pbuffer++) = '-';
    }

    *(pbuffer) = '\0';

    u32 len = (pbuffer - buffer);
    for (i32 i = 0; i < len / 2; i++) {
        char j = buffer[i];
        buffer[i] = buffer[len-i-1];
        buffer[len-i-1] = j;
    }

    return len;
}

struct mini_buff {
    char * buffer;
    char * pbuffer;
    u32 buffer_len;
};

static int putc(i32 ch, struct mini_buff * b)
{
    if ((u32)((b->pbuffer - b->buffer) + 1) >= b->buffer_len) {
        return 0;
    }
    *(b->pbuffer++) = ch;
    *(b->pbuffer) = '\0';
    return 1;
}

static int puts(char * s, u32 len, struct mini_buff * b)
{
    u32 i;

    if (b->buffer_len - (b->pbuffer - b->buffer) - 1 < len) {
        len = b->buffer_len - (b->pbuffer - b->buffer) - 1;
    }

    for (i = 0; i < len; i++) {
        *(b->pbuffer++) = s[i];
    }

    *(b->pbuffer) = '\0';

    return len;
}

i32 vsnprintf(char * buffer, u32 buffer_len, const char * fmt, __builtin_va_list va)
{
    struct mini_buff b = {};
    char bf[24] = {};
    char ch = 0;

    uart_puts("Hej");

    b.buffer = buffer;
    b.pbuffer = buffer;
    b.buffer_len = buffer_len;

    while ((ch = *(fmt++))) {
        if ((u32)((b.pbuffer - b.buffer) + 1) >= b.buffer_len) {
            break;
        }

        if (ch != '%') {
            putc(ch, &b);
        } else {
            char zero_pad = 0;
            char * ptr = NULL;
            u32 len = 0;

            ch = *(fmt++);

            if (ch == '0') {
                ch =* (fmt++);
                if (ch == '\0') {
                    goto end;
                }
                if (ch >= '0' && ch <= '9') {
                    zero_pad = ch - '0';
                }
                ch = *(fmt++);
            }

            switch (ch) {
                case 0:
                    goto end;

                case 'u':
                case 'd':
                    len = itoa(__builtin_va_arg(va, u32), 10, 0, (ch=='u'), bf, zero_pad);
                    puts(bf, len, &b);
                    break;

                case 'x':
                case 'X':
                    len = itoa(__builtin_va_arg(va, u32), 16, (ch=='X'), 1, bf, zero_pad);
                    puts(bf, len, &b);
                    break;

                case 'c' :
                    putc((char)(__builtin_va_arg(va, int)), &b);
                    break;

                case 's' :
                    ptr = __builtin_va_arg(va, char *);
                    puts(ptr, strlen(ptr), &b);
                    break;

                default:
                    putc(ch, &b);
                    break;
            }
        }
    }
end:
    return b.pbuffer - b.buffer;
}


i32 snprintf(char * buffer, u32 buffer_len, const char *fmt, ...)
{
    uart_puts("Hej");

    __builtin_va_list va;
    __builtin_va_start(va, fmt);
    i32 ret = vsnprintf(buffer, buffer_len, fmt, va);
    __builtin_va_end(va);
    return ret;
}
