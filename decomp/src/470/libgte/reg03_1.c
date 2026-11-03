#include "common.h"

void SetVertex0(void* p) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     "lwc2 $1, 4(%0)"
                     : : "r"(p) : "memory");
}
