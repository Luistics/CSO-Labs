#include <assert.h>

#include "part4.h"

//Luis Olivar lao294

long foo(long* p, long val)
{
    long result = *p;
    val = val + result;
    *p = val;
    return result;
    //assert(0);
    //return 0;
}

long part4(long* array, int size)
{
    long result;
    long* r13 = array;
    int r12d = size;
    int ebx = 0;
    int ebp = 0;

    while(ebx < r12d)
    {
        long t = ebx;
        //line 25
        array = &r13[t];
        int val = 2;
        ebp += foo(array,val);
        ebx++;
    }

    result = ebp;
    return result;

}
