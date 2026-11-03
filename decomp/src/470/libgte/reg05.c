#include "common.h"

void ReadSZfifo4(void* a, void* b, void* c, void* d) {
    __asm__ volatile("swc2 $16, 0(%0)\n\t"
                     "swc2 $17, 0(%1)\n\t"
                     "swc2 $18, 0(%2)\n\t"
                     "swc2 $19, 0(%3)"
                     : : "r"(a), "r"(b), "r"(c), "r"(d) : "memory");
}
