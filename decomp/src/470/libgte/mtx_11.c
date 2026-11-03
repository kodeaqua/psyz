#include "common.h"
#include <og/libgte.h>

void SetColorMatrix(MATRIX* m) {
    __asm__ volatile("lw $8, 0(%0)\n\t"
                     "lw $9, 4(%0)\n\t"
                     "lw $10, 8(%0)\n\t"
                     "lw $11, 12(%0)\n\t"
                     "lw $12, 16(%0)\n\t"
                     "ctc2 $8, $16\n\t"
                     "ctc2 $9, $17\n\t"
                     "ctc2 $10, $18\n\t"
                     "ctc2 $11, $19\n\t"
                     "ctc2 $12, $20"
                     : : "r"(m) : "t0", "t1", "t2", "t3", "t4", "memory");
}
