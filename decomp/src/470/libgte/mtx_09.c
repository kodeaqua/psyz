#include "common.h"
#include <og/libgte.h>

void SetRotMatrix(MATRIX* m) {
    __asm__ volatile("lw $8, 0(%0)\n\t"
                     "lw $9, 4(%0)\n\t"
                     "lw $10, 8(%0)\n\t"
                     "lw $11, 12(%0)\n\t"
                     "lw $12, 16(%0)\n\t"
                     "ctc2 $8, $0\n\t"
                     "ctc2 $9, $1\n\t"
                     "ctc2 $10, $2\n\t"
                     "ctc2 $11, $3\n\t"
                     "ctc2 $12, $4"
                     : : "r"(m) : "t0", "t1", "t2", "t3", "t4", "memory");
}
