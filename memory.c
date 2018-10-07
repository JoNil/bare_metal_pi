#include "types.h"

void * memset(void * ptr, i32 value, u64 num)
{
	u8 * p = (u8 *)ptr;

	for (u64 i = 0; i < num; ++i) {
		p[i] = value;
	}

	return ptr;
}