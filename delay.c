#include "delay.h"
#include "gpio.h"

#define SYSTMR_LO ((volatile unsigned int*)(MMIO_BASE + 0x00003004))
#define SYSTMR_HI ((volatile unsigned int*)(MMIO_BASE + 0x00003008))

void wait_cycles(unsigned int n)
{
    if(n) while(n--) { asm volatile("nop"); }
}

void wait_msec(unsigned int n)
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

unsigned long get_system_timer()
{
    u32 h = -1;
    u32 l = 0;
    
    h = *SYSTMR_HI;
    l = *SYSTMR_LO;
    
    if (h != *SYSTMR_HI) {
        h = *SYSTMR_HI;
        l = *SYSTMR_LO;
    }
    
    return ((u64)h << 32) | l;
}

void wait_msec_st(unsigned int n)
{
    u64 t = get_system_timer();
    
    if (t) while (get_system_timer() < t+n);
}
