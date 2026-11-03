#include "common.h"
#include <og/libgte.h>

void NormalColor3(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, CVECTOR* v3, CVECTOR* v4, CVECTOR* v5) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     ".word 0xC8810004\n\t"
                     ".word 0xC8A20000\n\t"
                     ".word 0xC8A30004\n\t"
                     ".word 0xC8C40000\n\t"
                     ".word 0xC8C50004\n\t"
                     "nop\n\t"
                     ".word 0x4AD80420\n\t"
                     "lw $8, 16($sp)\n\t"
                     "lw $9, 20($sp)\n\t"
                     "swc2 $20, 0(%3)\n\t"
                     "swc2 $21, 0($8)\n\t"
                     "swc2 $22, 0($9)"
                     : : "r"(v0), "r"(v1), "r"(v2), "r"(v3)
                     : "t0", "t1", "memory");
}
