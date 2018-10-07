#include "framebuffer.h"
#include "types.h"

void main()
{
    framebuffer_init();

    i32 x = 100;
    i32 y = 100;
    i32 dx = 1;
    i32 dy = 1;

    for (;;) {

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

        framebuffer_swap();
    }
}
