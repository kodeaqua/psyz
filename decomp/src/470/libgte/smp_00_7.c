#include "common.h"
#include <og/libgte.h>

long AverageZ3(long sz0, long sz1, long sz2) {
    register long value asm("v0");
    __asm__ volatile("mtc2 %1, $17\n\t"
                     "mtc2 %2, $18\n\t"
                     "mtc2 %3, $19\n\t"
                     "nop\n\t"
                     ".word 0x4B58002D\n\t"
                     "mfc2 %0, $7"
                     : "=r"(value) : "r"(sz0), "r"(sz1), "r"(sz2));
    return value;
}
