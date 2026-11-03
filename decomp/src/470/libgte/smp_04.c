#include "common.h"
#include <og/libgte.h>

void RotTrans(SVECTOR* v0, VECTOR* v1, long* flag) {
    register s32 value asm("v0");
    __asm__ volatile("lwc2 $0, 0(%1)\n\t"
                     "lwc2 $1, 4(%1)\n\t"
                     "nop\n\t"
                     ".word 0x4A480012\n\t"
                     "swc2 $25, 0(%2)\n\t"
                     "swc2 $26, 4(%2)\n\t"
                     "swc2 $27, 8(%2)\n\t"
                     "cfc2 %0, $31"
                     : "=r"(value) : "r"(v0), "r"(v1) : "memory");
    *flag = value;
}
