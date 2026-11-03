#include "common.h"
#include <og/libgte.h>

void RotTransSV(SVECTOR* v0, SVECTOR* v1, long* flag) {
    register long value asm("v0");
    __asm__ volatile("lwc2 $0, 0(%1)\n\t"
                     "lwc2 $1, 4(%1)\n\t"
                     "nop\n\t"
                     ".word 0x4A480012\n\t"
                     "mfc2 $2, $9\n\t"
                     "mfc2 $3, $10\n\t"
                     "swc2 $11, 4(%2)\n\t"
                     "sh $2, 0(%2)\n\t"
                     "sh $3, 2(%2)\n\t"
                     "cfc2 %0, $31"
                     : "=r"(value) : "r"(v0), "r"(v1)
                     : "v1", "memory");
    *flag = value;
}
