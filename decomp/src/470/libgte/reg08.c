#include "common.h"
#include <og/libgte.h>

void ReadGeomOffset(long* ofx, long* ofy) {
    __asm__ volatile("cfc2 $8, $24\n\t"
                     "cfc2 $9, $25\n\t"
                     "sra $8, $8, 16\n\t"
                     "sra $9, $9, 16\n\t"
                     "sw $8, 0(%0)\n\t"
                     "sw $9, 0(%1)"
                     : : "r"(ofx), "r"(ofy) : "t0", "t1", "memory");
}
