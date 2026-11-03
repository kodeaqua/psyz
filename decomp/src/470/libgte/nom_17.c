#include "common.h"
#include <og/libgte.h>

void NormalColorCol3_nom(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, CVECTOR* v3) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     ".word 0xC8810004\n\t"
                     ".word 0xC8A20000\n\t"
                     ".word 0xC8A30004\n\t"
                     ".word 0xC8C40000\n\t"
                     ".word 0xC8C50004\n\t"
                     ".word 0xC8E60000\n\t"
                     "nop\n\t"
                     ".word 0x4B18043F"
                     : : "r"(v0), "r"(v1), "r"(v2), "r"(v3) : "memory");
}
