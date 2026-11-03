#include "common.h"

s32 ReadFLAG(void) {
    register s32 value asm("v0");
    __asm__ volatile("cfc2 %0, $31" : "=r"(value));
    return value;
}
