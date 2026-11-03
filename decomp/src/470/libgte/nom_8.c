#include "common.h"
#include <og/libgte.h>

void RotColorDpq_nom(SVECTOR* v0, SVECTOR* v1, CVECTOR* v2) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "nop\n\t"
                     ".word 0x4A180001\n\t"
                     "cfc2 $2, $31\n\t"
                     ".word 0xC8A00000\n\t"
                     ".word 0xC8A10004\n\t"
                     ".word 0xC8C60000\n\t"
                     "nop\n\t"
                     ".word 0x4AE80413"
                     : : "r"(v0), "r"(v1), "r"(v2) : "v0", "memory");
}
