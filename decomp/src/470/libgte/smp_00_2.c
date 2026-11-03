#include "common.h"
#include <og/libgte.h>

void DpqColorLight(VECTOR* v0, CVECTOR* v1, long p, CVECTOR* v2) {
    __asm__ volatile("lwc2 $9, 0(%0)\n\t"
                     "lwc2 $10, 4(%0)\n\t"
                     "lwc2 $11, 8(%0)\n\t"
                     ".word 0xC8A60000\n\t"
                     "mtc2 %2, $8\n\t"
                     "nop\n\t"
                     ".word 0x4A680029\n\t"
                     "swc2 $22, 0(%3)"
                     : : "r"(v0), "r"(v1), "r"(p), "r"(v2) : "memory");
}
