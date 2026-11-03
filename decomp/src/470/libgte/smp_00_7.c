#include "common.h"

s32 AverageZ3(s32 sz0, s32 sz1, s32 sz2) {
    register s32 value asm("v0");
    __asm__ volatile("mtc2 %1, $17\n\t"
                     "mtc2 %2, $18\n\t"
                     "mtc2 %3, $19\n\t"
                     "nop\n\t"
                     ".word 0x4B58002D\n\t"
                     "mfc2 %0, $7"
                     : "=r"(value) : "r"(sz0), "r"(sz1), "r"(sz2));
    return value;
}
