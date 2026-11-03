#include "common.h"
#include <og/libgte.h>

void Intpl(VECTOR* v0, long p, CVECTOR* v1) {
    __asm__ volatile("lwc2 $9, 0(%0)\n\t"
                     "lwc2 $10, 4(%0)\n\t"
                     "lwc2 $11, 8(%0)\n\t"
                     "mtc2 %1, $8\n\t"
                     "nop\n\t"
                     ".word 0x4A980011\n\t"
                     "swc2 $22, 0(%2)"
                     : : "r"(v0), "r"(p), "r"(v1) : "memory");
}
