#include "common.h"
#include <og/libgte.h>

void ReadSZfifo4(long* szx, long* sz0, long* sz1, long* sz2) {
    __asm__ volatile("swc2 $16, 0(%0)\n\t"
                     "swc2 $17, 0(%1)\n\t"
                     "swc2 $18, 0(%2)\n\t"
                     "swc2 $19, 0(%3)"
                     : : "r"(szx), "r"(sz0), "r"(sz1), "r"(sz2) : "memory");
}
