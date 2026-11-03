#include "common.h"

s32 GetSp(void) {
    register s32 sp_value asm("sp");
    return sp_value;
}
