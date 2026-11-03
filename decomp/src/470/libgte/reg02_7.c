#include "common.h"

void ReadORGB(u32* v0) {
    register u32 orgb asm("t0");
    register u32 component asm("t1");
    volatile u32* output = (volatile u32*)v0;
    __asm__ volatile("mfc2 %0, $29\n\tnop" : "=r"(orgb));
    component = orgb & 0x1F;
    output[0] = component;
    component = (orgb & 0x3E0) >> 5;
    output[1] = component;
    /* Keep the source value in t0 while the final component is generated. */
    __asm__ volatile("" : "+r"(orgb));
    component = (orgb & 0x7C00) >> 10;
    output[2] = component;
    /* The PSY-Q sequence leaves t0 unchanged through the final store. */
    __asm__ volatile("" : : "r"(orgb));
}
