#include "common.h"

void SetVertexTri(void* a, void* b, void* c) {
    __asm__ volatile("lwc2 $0, 0(%0)\n\t"
                     ".word 0xC8810004\n\t"
                     ".word 0xC8A20000\n\t"
                     ".word 0xC8A30004\n\t"
                     ".word 0xC8C40000\n\t"
                     ".word 0xC8C50004"
                     : : "r"(a), "r"(b), "r"(c) : "memory");
}
