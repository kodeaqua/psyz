#include "common.h"
#include <og/libgte.h>

void SetLightMatrix(MATRIX* m) {
    __asm__ volatile("lw $8, 0(%0)\n\t"
                     "lw $9, 4(%0)\n\t"
                     "lw $10, 8(%0)\n\t"
                     "lw $11, 12(%0)\n\t"
                     "lw $12, 16(%0)\n\t"
                     "ctc2 $8, $8\n\t"
                     "ctc2 $9, $9\n\t"
                     "ctc2 $10, $10\n\t"
                     "ctc2 $11, $11\n\t"
                     "ctc2 $12, $12"
                     : : "r"(m) : "t0", "t1", "t2", "t3", "t4", "memory");
}
