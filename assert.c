#include "assert.h"
#include "types.h"

void abort(void)
{
	do { asm volatile("nop"); } while (1);
}