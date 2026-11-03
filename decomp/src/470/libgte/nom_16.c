#include "common.h"

void NormalColorCol_nom(void* v0, void* v1) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "lwc2 $6, 0(%1)\n\t"
                     "nop\n\t"
                     ".word 0x4B08041B"
                     : : "r"(v0), "r"(v1) : "memory");
}
