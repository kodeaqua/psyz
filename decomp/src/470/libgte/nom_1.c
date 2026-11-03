#include "common.h"
#include <og/libgte.h>

void RotTransPers_nom(SVECTOR* v0) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "nop\n\t"
                     ".word 0x4A180001"
                     : : "r"(v0) : "memory");
}
