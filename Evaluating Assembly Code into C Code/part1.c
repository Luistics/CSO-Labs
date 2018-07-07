#include <assert.h>

#include "part1.h"

//Luis Olivar lao294

long part1(long x, long y)
{
    long result;
    if(x <= y)
    {
        result = y;
        return result;
    }
    else
    {
        result = x;
        return result;
    }
    //assert(0);
    //return 0;
}
