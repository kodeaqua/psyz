#include "common.h"

void SetRGBfifo(void* a, void* b, void* c) {
    __asm__ volatile("lwc2 $20, 0(%0)\n\t"
                     "lwc2 $21, 0(%1)\n\t"
                     "lwc2 $22, 0(%2)"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
