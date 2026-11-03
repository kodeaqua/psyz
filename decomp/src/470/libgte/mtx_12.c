#include "common.h"
#include <og/libgte.h>

void SetTransMatrix(MATRIX* m) {
    __asm__ volatile("lw $8, 20(%0)\n\t"
                     "lw $9, 24(%0)\n\t"
                     "lw $10, 28(%0)\n\t"
                     "ctc2 $8, $5\n\t"
                     "ctc2 $9, $6\n\t"
                     "ctc2 $10, $7"
                     : : "r"(m) : "t0", "t1", "t2", "memory");
}
