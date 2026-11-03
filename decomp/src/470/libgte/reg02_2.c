#include "common.h"

s32 ReadIR0(void) {
    register s32 value asm("v0");
    __asm__ volatile("mfc2 %0, $8" : "=r"(value));
    return value;
}
