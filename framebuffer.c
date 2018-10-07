#include "assert.h"
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

    mbox[2] = 0x48003;  // Set phy wh
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = 1280;     // FrameBufferInfo.width
    mbox[6] = 720;      // FrameBufferInfo.height

    mbox[7] = 0x48004;  // Set virt wh
    mbox[8] = 8;
    mbox[9] = 8;
    mbox[10] = 1280;    // FrameBufferInfo.virtual_width
    mbox[11] = 1440;    // FrameBufferInfo.virtual_height
    
    mbox[12] = 0x48009; // Set virt offset
    mbox[13] = 8;
    mbox[14] = 8;
    mbox[15] = 0;       // FrameBufferInfo.x_offset
    mbox[16] = 0;       // FrameBufferInfo.y.offset
    
    mbox[17] = 0x48005; // Set depth
    mbox[18] = 4;
    mbox[19] = 4;
    mbox[20] = 32;      // FrameBufferInfo.depth

    mbox[21] = 0x48006; // Set pixel order
    mbox[22] = 4;
    mbox[23] = 4;
    mbox[24] = 0;       //RGB, not BGR preferably

    mbox[25] = 0x40001; // Get framebuffer, gets alignment on request
    mbox[26] = 8;
    mbox[27] = 8;
    mbox[28] = 4096;    // FrameBufferInfo.pointer
    mbox[29] = 0;       // FrameBufferInfo.size

    mbox[30] = 0x40008; // Get pitch
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

    current_buffer = framebuffer;
}
void framebuffer_clear(void) {

    u32 color = 0xff240A30;

    for (i32 i = 0; i < height; ++i) {

        u8 * line = current_buffer + pitch*i;

        for (i32 j = 0; j < width; ++j) {

            *(u32 *)line = color;
            line += 4;
        }
    }
}

void framebuffer_draw(i32 x, i32 y) {

    u8 * ptr = current_buffer + 4*x + pitch*y;

    u8 * line = ptr;

    u32 color = 0xff00ff00;

    for (i32 i = 0; i < 100; ++i) {

        line = ptr + pitch*i;

        for (i32 j = 0; j < 100; ++j) {

            *(u32 *)line = color;
            line += 4;
        }
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

    mbox[2] = 0x48009 ;  // Set Virtual Offset
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = 0;        // x offset
    mbox[6] = y_offset; // y offset

    mbox[7] = MBOX_TAG_LAST;

    i32 ret = mbox_call(MBOX_CH_PROP);
    assert(ret);
}