#pragma once

#include "types.h"

void framebuffer_init(void);
void framebuffer_clear(void);
void framebuffer_draw(int x, int y);
void framebuffer_text(int x, int y, const char * str);
void framebuffer_swap();
u8 * framebuffer_pointer();
