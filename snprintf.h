#pragma once

#include "types.h"

int vsnprintf(char * buffer, u32 buffer_len, const char * fmt, __builtin_va_list va);
int snprintf(char * buffer, u32 buffer_len, const char * fmt, ...);
