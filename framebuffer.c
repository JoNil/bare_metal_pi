#include "mbox.h"

unsigned int width;
unsigned int height;
unsigned int pitch;
unsigned char * framebuffer;

void framebuffer_init(void)
{
    unsigned int index = 0;

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

    /*mbox[index++] = 0x4800a; // Set overscan
    mbox[index++] = 16;
    mbox[index++] = 16;
    mbox[index++] = 0;
    mbox[index++] = 0;
    mbox[index++] = 0;
    mbox[index++] = 0;*/

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
        framebuffer = (void*)((unsigned long)mbox[28]);
    }
}

void framebuffer_clear(void) {

    unsigned int color = 0xff240A30;

    for (int i = 0; i < height; ++i) {

        unsigned char * line = framebuffer + pitch*i;

        for (int j = 0; j < width; ++j) {

            *(unsigned int *)line = color;
            line += 4;
        }
    }
}

void framebuffer_draw(int x, int y) {

    unsigned char * ptr = framebuffer + 4*x + pitch*y;

    unsigned char * line = ptr;

    unsigned int color = 0xff00ff00;

    for (int i = 0; i < 100; ++i) {

        line = ptr + pitch*i;

        for (int j = 0; j < 100; ++j) {

            *(unsigned int *)line = color;
            line += 4;
        }
    }
}
