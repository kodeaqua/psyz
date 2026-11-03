#include "common.h"
#include <og/libgte.h>

long Lzc(long data) {
    register long value asm("v0");
    __asm__ volatile("mtc2 %1, $30\n\t"
                     "nop\n\t"
                     "nop\n\t"
                     "mfc2 %0, $31"
                     : "=r"(value) : "r"(data));
    return value;
}
