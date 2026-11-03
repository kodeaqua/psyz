#include "common.h"

void SetVertex1(void* p) {
    __asm__ volatile("lwc2 $2, 0(%0)\n\t"
                     "lwc2 $3, 4(%0)"
                     : : "r"(p) : "memory");
}
