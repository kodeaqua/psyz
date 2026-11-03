#include "common.h"
#include <og/libgte.h>

long RotTransPers(SVECTOR* v0, long* sxy, long* p, long* flag) {
    register long value asm("v0");
    __asm__ volatile("lwc2 $0, 0(%1)\n\t"
                     "lwc2 $1, 4(%1)\n\t"
                     "nop\n\t"
                     ".word 0x4A180001\n\t"
                     "swc2 $14, 0(%2)\n\t"
                     "swc2 $8, 0(%3)\n\t"
                     "cfc2 $3, $31\n\t"
                     "mfc2 %0, $19\n\t"
                     "sw $3, 0(%4)"
                     : "=r"(value)
                     : "r"(v0), "r"(sxy), "r"(p), "r"(flag)
                     : "v1", "memory");
    return value >> 2;
}
