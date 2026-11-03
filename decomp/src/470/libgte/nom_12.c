#include "common.h"

void NormalColor_nom(void* v0) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "nop\n\t"
                     ".word 0x4AC8041E"
                     : : "r"(v0) : "memory");
}
