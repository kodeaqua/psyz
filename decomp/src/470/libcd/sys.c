#include "common.h"
#include <og/libcd.h>

int CdPosToInt(CdlLOC* p) {
#define DECODE_BCD(x) (((x) >> 4) * 10 + ((x) & 0xF))
    u8 sector = p->sector;
    u8 second = p->second;
    u8 minute = p->minute;

    return (DECODE_BCD(minute) * 60 + DECODE_BCD(second)) * 75 +
           DECODE_BCD(sector) - 150;
}
