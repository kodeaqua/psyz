#include "common.h"

s32 ReadOTZ(void) {
    register s32 value asm("v0");
    __asm__ volatile("mfc2 %0, $7" : "=r"(value));
    return value;
}
