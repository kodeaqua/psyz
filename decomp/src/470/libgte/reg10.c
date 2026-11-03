#include "common.h"
#include <og/libgte.h>

void SetBackColor(long rbk, long gbk, long bbk) {
    __asm__ volatile("sll %0, %0, 4\n\t"
                     "sll %1, %1, 4\n\t"
                     "sll %2, %2, 4\n\t"
                     "ctc2 %0, $13\n\t"
                     "ctc2 %1, $14\n\t"
                     "ctc2 %2, $15"
                     : "+r"(rbk), "+r"(gbk), "+r"(bbk));
}
