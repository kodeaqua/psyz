#include "common.h"
#include <og/libgte.h>

void DpqColor3(CVECTOR* v0, CVECTOR* v1, CVECTOR* v2, long p, CVECTOR* v3, CVECTOR* v4, CVECTOR* v5) {
    __asm__ volatile("lwc2 $20, 0(%0)\n\t"
                     "lwc2 $21, 0(%1)\n\t"
                     "lwc2 $22, 0(%2)\n\t"
                     "lwc2 $6, 0(%2)\n\t"
                     "mtc2 %3, $8\n\t"
                     "nop\n\t"
                     ".word 0x4AF8002A\n\t"
                     "lw $8, 16($sp)\n\t"
                     "lw $9, 20($sp)\n\t"
                     "lw $10, 24($sp)\n\t"
                     "swc2 $20, 0($8)\n\t"
                     "swc2 $21, 0($9)\n\t"
                     "swc2 $22, 0($10)"
                     : : "r"(v0), "r"(v1), "r"(v2), "r"(p)
                     : "t0", "t1", "t2", "memory");
}
