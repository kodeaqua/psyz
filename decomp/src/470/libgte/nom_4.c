#include "common.h"
#include <og/libgte.h>

void RotTransPers4_nom(SVECTOR* v0, SVECTOR* v1, SVECTOR* v2, SVECTOR* v3) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     ".word 0xC8810004\n\t"
                     ".word 0xC8A20000\n\t"
                     ".word 0xC8A30004\n\t"
                     ".word 0xC8C40000\n\t"
                     ".word 0xC8C50004\n\t"
                     "nop\n\t"
                     ".word 0x4A280030\n\t"
                     "cfc2 $2, $31\n\t"
                     "mfc2 $3, $12\n\t"
                     ".word 0xC8E00000\n\t"
                     ".word 0xC8E10004\n\t"
                     "nop\n\t"
                     ".word 0x4A180001"
                     : : "r"(v0), "r"(v1), "r"(v2), "r"(v3)
                     : "v0", "v1", "memory");
}
