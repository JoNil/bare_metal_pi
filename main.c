#include "build_date.h"
#include "framebuffer.h"
#include "mmu.h"
#include "reload.h"
#include "str.h"
#include "time.h"
#include "types.h"
#include "uart.h"
#include "v3d.h"

const char * DATE = BUILD_DATE;

void main()
{
    uart_init();

    uart_puts("Uart inited\n");

    reload_initial(DATE);

    framebuffer_init();

    uart_puts("Framebuffer inited\n");

    //v3d_init();

    //uart_puts("V3d inited\n");

    i32 x = 100;
    i32 y = 100;
    i32 dx = 1;
    i32 dy = 1;

    i32 last_frame_time = 0;

    for (;;) {

        u64 start = time_usec();

        x += dx;
        y += dy;

        if (x > 200) {
            dx = -1;
            x = 200;
        }

        if (x < 100) {
            dx = 1;
            x = 100;
        }

        if (y > 200) {
            dy = -1;
            y = 200;
        }

        if (y < 100) {
            dy = 1;
            y = 100;
        }

        framebuffer_clear();

        framebuffer_draw(x, y);

        framebuffer_text(100, 400, "Hi this is a long string with text");

        {
            char buffer[128] = {};
            i32_to_string(buffer, sizeof(buffer), last_frame_time / 1000);

            framebuffer_text(12, 14, buffer);
            uart_puts(buffer);
            uart_send('\n');
        }

        framebuffer_swap();

        u64 end = time_usec();
        last_frame_time = (i32)(end - start);

        reload_initial(DATE);
    }
}
