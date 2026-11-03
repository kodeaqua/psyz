#include "common.h"

s32 AverageSZ3(void) {
    register s32 value asm("v0");
    __asm__ volatile(".word 0x4B58002D\n\t"
                     "mfc2 %0, $7"
                     : "=r"(value));
    return value;
}
