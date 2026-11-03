#include "common.h"

void ReadSZ2(void* p) {
    __asm__ volatile("swc2 $19, 0(%0)" : : "r"(p) : "memory");
}
