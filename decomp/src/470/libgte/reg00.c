#include "common.h"
#include <og/libgte.h>

void SetRGBcd(CVECTOR* v) {
    __asm__ volatile("lwc2 $6, 0(%0)" : : "r"(v) : "memory");
}
