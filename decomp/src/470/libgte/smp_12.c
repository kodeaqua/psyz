#include "common.h"

s32 AverageSZ4(void) {
    register s32 value asm("v0");
    __asm__ volatile(".word 0x4B68002E\n\t"
                     "mfc2 %0, $7"
                     : "=r"(value));
    return value;
}
