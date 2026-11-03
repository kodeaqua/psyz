#include "common.h"
#include <og/libgte.h>

void ReadSXSYfifo(long* sxy0, long* sxy1, long* sxy2) {
    __asm__ volatile("swc2 $12, 0(%0)\n\t"
                     "swc2 $13, 0(%1)\n\t"
                     "swc2 $14, 0(%2)"
                     : : "r"(sxy0), "r"(sxy1), "r"(sxy2) : "memory");
}
