#include "common.h"

s32 ReadLZC(void) {
    register s32 value asm("v0");
    __asm__ volatile("mfc2 %0, $31" : "=r"(value));
    return value;
}
