#include "common.h"

void SetRGBcd(void* p) {
    __asm__ volatile("lwc2 $6, 0(%0)" : : "r"(p) : "memory");
}
