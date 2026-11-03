#include "common.h"

void ReadIR123(void* a, void* b, void* c) {
    __asm__ volatile("swc2 $9, 0(%0)\n\t"
                     "swc2 $10, 0(%1)\n\t"
                     "swc2 $11, 0(%2)"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
