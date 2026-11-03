#include "common.h"

void NormalColorCol(void* v0, void* v1, void* v2) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "lwc2 $6, 0(%1)\n\t"
                     "nop\n\t"
                     ".word 0x4B08041B\n\t"
                     "swc2 $22, 0(%2)"
                     : : "r"(v0), "r"(v1), "r"(v2) : "memory");
}
