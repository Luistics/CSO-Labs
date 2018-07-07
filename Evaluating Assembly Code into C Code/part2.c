#include <assert.h>

#include "part2.h"

//Luis Olivar lao294

long part2(long x, long y)
{
    //lines 0 and 4 from assembler (lea math)
    long result = x * 24;
    long* temp = &y + 0x1f;
    if(y >= 0)
    {
        *temp = y;
    }

    *temp = *temp >> 5;
    result = *temp & result;
    return result;

    //assert(0);
    //return 0;
}
