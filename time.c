#include "gpio.h"
#include "time.h"

#define SYSTMR_LO ((volatile u32 *)(MMIO_BASE + 0x00003004))
#define SYSTMR_HI ((volatile u32 *)(MMIO_BASE + 0x00003008))

void wait_cycles(u32 n)
{
    if (n) while(n--) { asm volatile("nop"); }
}

void wait_usec(u32 n)
{
    register u64 f;
    register u64 t;
    register u64 r;

    // get the current counter frequency
    asm volatile ("mrs %0, cntfrq_el0" : "=r"(f));
    // read the current counter
    asm volatile ("mrs %0, cntpct_el0" : "=r"(t));
    // calculate expire value for counter
    t += ((f/1000)*n)/1000;
    do { asm volatile ("mrs %0, cntpct_el0" : "=r"(r)); } while (r<t);
}

u64 time_usec(void)
{
    u32 h = *SYSTMR_HI;
    u32 l = *SYSTMR_LO;

    if (h != *SYSTMR_HI) {
        h = *SYSTMR_HI;
        l = *SYSTMR_LO;
    }
    
    return ((u64)h << 32) | l;
}
