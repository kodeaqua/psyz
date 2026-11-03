#include "common.h"

s32 NormalClip(s32 sxy0, s32 sxy1, s32 sxy2) {
    register s32 value asm("v0");
    __asm__ volatile("mtc2 %1, $12\n\t"
                     "mtc2 %3, $14\n\t"
                     "mtc2 %2, $13\n\t"
                     "nop\n\t"
                     "nop\n\t"
                     ".word 0x4B400006\n\t"
                     "mfc2 %0, $24"
                     : "=r"(value) : "r"(sxy0), "r"(sxy1), "r"(sxy2));
    return value;
}
