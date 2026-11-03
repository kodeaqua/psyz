#include "common.h"

void ReadRGBfifo(void* a, void* b, void* c) {
    __asm__ volatile("swc2 $20, 0(%0)\n\t"
                     "swc2 $21, 0(%1)\n\t"
                     "swc2 $22, 0(%2)"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
