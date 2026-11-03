#include "common.h"
#include <og/libgte.h>

long AverageZ4(long sz0, long sz1, long sz2, long sz3) {
    register long value asm("v0");
    __asm__ volatile("mtc2 %1, $16\n\t"
                     "mtc2 %2, $17\n\t"
                     "mtc2 %3, $18\n\t"
                     "mtc2 %4, $19\n\t"
                     "nop\n\t"
                     ".word 0x4B68002E\n\t"
                     "mfc2 %0, $7"
                     : "=r"(value) : "r"(sz0), "r"(sz1), "r"(sz2), "r"(sz3));
    return value;
}
