#include "str.h"
#include "types.h"

void i32_to_string(char * buffer, i32 size, i32 v)
{
    i32 index = 0;

    do {
        buffer[index++] = 0x30 + v % 10;
        v /= 10;
    } while (v != 0 && index < size);

    index -= 1;

    for (i32 i = 0; i < (index + 1) / 2; ++i) {
    	char tmp = buffer[i];
    	buffer[i] = buffer[index - i];
    	buffer[index - i] = tmp;
    }
}