#include "common.h"

void ReadMAC123(void* a, void* b, void* c) {
    __asm__ volatile("swc2 $25, 0(%0)\n\t"
                     "swc2 $26, 0(%1)\n\t"
                     "swc2 $27, 0(%2)"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
