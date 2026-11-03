#include "common.h"
#include <og/libgte.h>

MATRIX* TransMatrix(MATRIX* m, VECTOR* v) {
    register MATRIX* result asm("v0");
    __asm__ volatile("lw $8, 0(%2)\n\t"
                     "lw $9, 4(%2)\n\t"
                     "lw $10, 8(%2)\n\t"
                     "sw $8, 20(%1)\n\t"
                     "sw $9, 24(%1)\n\t"
                     "sw $10, 28(%1)\n\t"
                     "move %0, %1"
                     : "=r"(result) : "r"(m), "r"(v)
                     : "t0", "t1", "t2", "memory");
    return result;
}
