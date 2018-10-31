#pragma once

#define NULL 0
#define ARRAY_COUNT(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef signed char i8;
typedef unsigned char u8;

typedef short i16;
typedef unsigned short u16;

typedef int i32;
typedef unsigned int u32;

typedef long long i64;
typedef unsigned long long u64;

typedef float r32;

_Static_assert(sizeof(void *) == 8, "Error");

_Static_assert(sizeof(i8) == 1, "Error");
_Static_assert(sizeof(u8) == 1, "Error");

_Static_assert(sizeof(i16) == 2, "Error");
_Static_assert(sizeof(u16) == 2, "Error");

_Static_assert(sizeof(i32) == 4, "Error");
_Static_assert(sizeof(u32) == 4, "Error");

_Static_assert(sizeof(i64) == 8, "Error");
_Static_assert(sizeof(u64) == 8, "Error");

_Static_assert(sizeof(r32) == 4, "Error");