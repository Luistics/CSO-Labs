#include <assert.h>

#include <stdlib.h>

#include "part5.h"

//Luis Olivar lao294 


long bar(long * a, int size)
{
    int edx = 0;
    int r8d = 1;
    int result = 0;
    size = size - 1;

    while(size > edx)
    {
        long rcx = edx;
        rcx = a[rcx];
        result += rcx;
        r8d = r8d * rcx;
        edx++;
    }

    result += r8d;
    return result;
}

long part5(int size)
{
    int esi = size;
    //lines 30-3f in assembler are just manipulating stack for the following line
    long* r8 = (long*) malloc(size * sizeof(long));
    int rax = 0;
    while(rax < esi)
    {
        long ecx = rax * 2;
        long rcx = ecx;
        long rdx = rax;
        r8[rdx] = rcx;
        rax++;
    }
    //@param array and size.
    long t = bar(r8,esi);

    free(r8);

    return t;

}
