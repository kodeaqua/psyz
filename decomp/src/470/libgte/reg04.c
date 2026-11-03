#include "common.h"

void ReadSZfifo3(void* a, void* b, void* c) {
    __asm__ volatile("swc2 $17, 0(%0)\n\t"
                     "swc2 $18, 0(%1)\n\t"
                     "swc2 $19, 0(%2)"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
