#include "common.h"

void ReadSXSYfifo(void* a, void* b, void* c) {
    __asm__ volatile("swc2 $12, 0(%0)\n\t"
                     "swc2 $13, 0(%1)\n\t"
                     "swc2 $14, 0(%2)"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
