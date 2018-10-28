#include "assert.h"
#include "mbox.h"
#include "v3d.h"

void v3d_init(void)
{
    mbox[0] = 12*4;
    mbox[1] = MBOX_REQUEST;

    mbox[2] = MBOX_TAG_SET_CLOCK_RATE;
    mbox[3] = 8;
    mbox[4] = 8;
    mbox[5] = CLK_V3D_ID;
    mbox[6] = 250*1000*1000;

    mbox[7] = MBOX_TAG_ENABLE_QPU;
    mbox[8] = 4;
    mbox[9] = 4;
    mbox[10] = 1;

    mbox[11] = MBOX_TAG_LAST;

    i32 ret = mbox_call(MBOX_CH_PROP);
    assert(ret);
}