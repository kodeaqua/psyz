#include "common.h"
#include <og/libgte.h>

void NormalColor(SVECTOR* v0, CVECTOR* v1) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "nop\n\t"
                     ".word 0x4AC8041E\n\t"
                     "swc2 $22, 0(%1)"
                     : : "r"(v0), "r"(v1) : "memory");
}
