#include "common.h"
#include <og/libgte.h>

VECTOR* ApplyRotMatrix(SVECTOR* v0, VECTOR* v1) {
    register VECTOR* result asm("v0");
    __asm__ volatile("lw $8, 0(%1)\n\t"
                     "lw $9, 4(%1)\n\t"
                     "mtc2 $8, $0\n\t"
                     "mtc2 $9, $1\n\t"
                     "nop\n\t"
                     ".word 0x4A486012\n\t"
                     "swc2 $9, 0(%2)\n\t"
                     "swc2 $10, 4(%2)\n\t"
                     "swc2 $11, 8(%2)\n\t"
                     "move %0, %2"
                     : "=r"(result) : "r"(v0), "r"(v1)
                     : "t0", "t1", "memory");
    return result;
}
