#include "assert.h"
#include "font.h"
#include "mbox.h"
#include "types.h"

u32 width;
u32 height;
u32 pitch;
u8 * framebuffer;
u8 * current_buffer;

void framebuffer_init(void)
{
    mbox[0] = 35*4;
    mbox[1] = MBOX_REQUEST;

    mbox[2] = MBOX_TAG_SET_PHYSICAL_DISPLAY;
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = 1280;     // FrameBufferInfo.width
    mbox[6] = 720;      // FrameBufferInfo.height

    mbox[7] = MBOX_TAG_SET_VIRTUAL_BUFFER;
    mbox[8] = 8;
    mbox[9] = 8;
    mbox[10] = 1280;    // FrameBufferInfo.virtual_width
    mbox[11] = 1440;    // FrameBufferInfo.virtual_height
    
    mbox[12] = MBOX_TAG_SET_VIRTUAL_OFFSET;
    mbox[13] = 8;
    mbox[14] = 8;
    mbox[15] = 0;       // FrameBufferInfo.x_offset
    mbox[16] = 0;       // FrameBufferInfo.y.offset
    
    mbox[17] = MBOX_TAG_SET_DEPTH;
    mbox[18] = 4;
    mbox[19] = 4;
    mbox[20] = 32;      // FrameBufferInfo.depth

    mbox[21] = MBOX_TAG_SET_PIXEL_ORDER;
    mbox[22] = 4;
    mbox[23] = 4;
    mbox[24] = 0;       //RGB, not BGR preferably

    mbox[25] = MBOX_TAG_ALLOCATE_BUFFER;
    mbox[26] = 8;
    mbox[27] = 8;
    mbox[28] = 4096;    // FrameBufferInfo.pointer
    mbox[29] = 0;       // FrameBufferInfo.size

    mbox[30] = MBOX_TAG_GET_PITCH;
    mbox[31] = 4;
    mbox[32] = 4;
    mbox[33] = 0;       // FrameBufferInfo.pitch

    mbox[34] = MBOX_TAG_LAST;

    i32 ret = mbox_call(MBOX_CH_PROP);
    assert(ret);
    assert(mbox[20] == 32);
    assert(mbox[28] != 0);
        
    mbox[28] &= 0x3FFFFFFF;
    width = mbox[5];
    height = mbox[6];
    pitch = mbox[33];
    framebuffer = (void *)((u64)mbox[28]);

    current_buffer = framebuffer + height*pitch;
}
void framebuffer_clear(void)
{
    const u32 color = 0xff240A30;

    for (i32 i = 0; i < height; ++i) {

        u8 * line = current_buffer + pitch*i;

        for (i32 j = 0; j < width; ++j) {

            *(u32 *)line = color;
            line += 4;
        }
    }
}

void framebuffer_draw(i32 x, i32 y)
{
    const u32 color = 0xff00ff00;

    u8 * ptr = current_buffer + 4*x + pitch*y;

    for (i32 i = 0; i < 100; ++i) {

        u8 * line = ptr + pitch*i;

        for (i32 j = 0; j < 100; ++j) {

            *(u32 *)line = color;
            line += 4;
        }
    }
}

void framebuffer_text(i32 x, i32 y, const char * str)
{
    const u32 color = 0xfff0f0f0;

    i32 x_offset = 0;

    while (*str != 0) {

        const u8 * glyph = font + 8 * (*str - 0x20);
        u8 * ptr = current_buffer + 4*(x + x_offset) + pitch*y;

        for (i32 i = 0; i < 8; ++i) {

            const u8 * glyph_line = glyph + i;
            u8 * line = ptr + pitch*i;

            for (i32 j = 0 ; j < 8; ++j) {

                if ((*glyph_line >> (8 - j)) & 0x1) {
                    *(u32 *)line = color;
                }

                line += 4;
            }
        }

        str += 1;
        x_offset += 8;
    }
}

void framebuffer_swap()
{
    u32 y_offset = 0;

    if (current_buffer == framebuffer) {
        
        current_buffer = framebuffer + height*pitch;

    } else {
        y_offset = height;
        current_buffer = framebuffer;
    }

    mbox[0] = 8*4;
    mbox[1] = MBOX_REQUEST;

    mbox[2] = MBOX_TAG_SET_VIRTUAL_OFFSET;
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = 0;        // x offset
    mbox[6] = y_offset; // y offset

    mbox[7] = MBOX_TAG_LAST;

    i32 ret = mbox_call(MBOX_CH_PROP);
    assert(ret);
}