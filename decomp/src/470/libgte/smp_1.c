#include "common.h"

void LocalLight(void* v0, void* v1) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)\n\t"
                     "nop\n\t"
                     ".word 0x4A4A6412\n\t"
                     "swc2 $9, 0(%1)\n\t"
                     "swc2 $10, 4(%1)\n\t"
                     "swc2 $11, 8(%1)"
                     : : "r"(v0), "r"(v1) : "memory");
}
