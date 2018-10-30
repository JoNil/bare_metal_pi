#include "memcpy.h"
#include "types.h"

void * memcpy(void * dst, const void * src, i32 num)
{
    u8 * d = dst;
    const u8 * s = src;
    for (i32 i = 0; i < num; i++) {
        d[i] = s[i];
    }

    return dst;
}