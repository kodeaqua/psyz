#include "common.h"

s32 ReadMac0(void) {
    register s32 value asm("v0");
    __asm__ volatile("mfc2 %0, $24" : "=r"(value));
    return value;
}
