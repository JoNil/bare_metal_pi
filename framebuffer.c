#include "mbox.h"
#include "types.h"

u32 width;
u32 height;
u32 pitch;
u8 * framebuffer;

u8 * current_buffer;

void framebuffer_init(void)
{
    u32 index = 0;

    mbox[index++] = 35*4;
    mbox[index++] = MBOX_REQUEST;

    mbox[index++] = 0x48003;  // Set phy wh
    mbox[index++] = 8;
    mbox[index++] = 8;
    mbox[index++] = 1280;     // FrameBufferInfo.width
    mbox[index++] = 720;      // FrameBufferInfo.height

    mbox[index++] = 0x48004;  // Set virt wh
    mbox[index++] = 8;
    mbox[index++] = 8;
    mbox[index++] = 1280;    // FrameBufferInfo.virtual_width
    mbox[index++] = 720;     // FrameBufferInfo.virtual_height
    
    mbox[index++] = 0x48009; // Set virt offset
    mbox[index++] = 8;
    mbox[index++] = 8;
    mbox[index++] = 0;       // FrameBufferInfo.x_offset
    mbox[index++] = 0;       // FrameBufferInfo.y.offset
    
    mbox[index++] = 0x48005; // Set depth
    mbox[index++] = 4;
    mbox[index++] = 4;
    mbox[index++] = 32;      // FrameBufferInfo.depth

    mbox[index++] = 0x48006; // Set pixel order
    mbox[index++] = 4;
    mbox[index++] = 4;
    mbox[index++] = 0;       //RGB, not BGR preferably

    mbox[index++] = 0x40001; // Get framebuffer, gets alignment on request
    mbox[index++] = 8;
    mbox[index++] = 8;
    mbox[index++] = 4096;    // FrameBufferInfo.pointer
    mbox[index++] = 0;       // FrameBufferInfo.size

    mbox[index++] = 0x40008; // Get pitch
    mbox[index++] = 4;
    mbox[index++] = 4;
    mbox[index++] = 0;       // FrameBufferInfo.pitch

    mbox[index++] = MBOX_TAG_LAST;

    if (mbox_call(MBOX_CH_PROP) && mbox[20] == 32 && mbox[28] != 0) {
        
        mbox[28] &= 0x3FFFFFFF;
        width = mbox[5];
        height = mbox[6];
        pitch = mbox[33];
        framebuffer = (void*)((u64)mbox[28]);
    }
}

void framebuffer_clear(void) {

    u32 color = 0xff240A30;

    for (i32 i = 0; i < height; ++i) {

        u8 * line = framebuffer + pitch*i;

        for (i32 j = 0; j < width; ++j) {

            *(u32 *)line = color;
            line += 4;
        }
    }
}

void framebuffer_draw(i32 x, i32 y) {

    u8 * ptr = framebuffer + 4*x + pitch*y;

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
