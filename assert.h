#pragma once

#define assert(x) ((void)(!(x) && (abort(), 1)))

void abort(void);