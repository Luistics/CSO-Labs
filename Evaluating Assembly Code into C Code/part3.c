#include <assert.h>

#include "part3.h"

//Luis Olivar lao294

char part3(long x, int b)
{
    char result;
    if(b < 0)
    {
        result = 0;
        return result;
    }
    else if(b > 7)
    {
        result = 0;
        return result;
    }
    else
    {
        //following 3 lines are line 9-10 in assembler
        int* p = &b;
        *p = *p * 8;
        x = x >> *p;
        result = x;
        return result;
    }


    //assert(0);
}
