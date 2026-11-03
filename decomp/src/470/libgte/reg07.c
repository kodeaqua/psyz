#include "common.h"
#include <og/libgte.h>

void ReadRGBfifo(CVECTOR* v0, CVECTOR* v1, CVECTOR* v2) {
    __asm__ volatile("swc2 $20, 0(%0)\n\t"
                     "swc2 $21, 0(%1)\n\t"
                     "swc2 $22, 0(%2)"
                     : : "r"(v0), "r"(v1), "r"(v2) : "memory");
}
