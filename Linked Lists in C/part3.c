#include <stdio.h>
#include <assert.h>
#include <limits.h>
#include <string.h>

/* Luis Olivar, lao294@nyu.edu, 02/28/2017*/

// Helper function
char* short_to_binary(unsigned short x);

// Write a function that determines a number
// is odd using only bitwise operators.
// Return 1 for true or 0 for false.
//
// This should only take a couple of lines.
int is_odd(int i)
{
    if(i & 1)
        return 1;
    return 0;
}

// Write a function that determines the number of 1
// bits in the computers internal representation
// of a given unsigned long integer using only bitwise operators.
int count_bits(unsigned long l)
{
    int count = 0;

    //right shift while checking if each bit is set or not
    while(l)
    {
        count += l & 1;
        l >>= 1;
    }

    return count;
}


// Write a function that takes two chars and
// 'interleaves' their bits into a short.
// Moreover, bits of x are in the even positions
// and y in the odd of the result.
// Ex. interleave_bits(1111, 0000) = 10101010
//     interleave_bits(0000, 1111) = 01010101
//     interleave_bits(0101, 1010) = 01100110
//     (fewer bits shown for clarity)
unsigned short interleave_bits(unsigned char x, unsigned char y)
{
    unsigned short z = 0;
    int i;

    //char size limit
    //fills in from left to right
    for(i = 0; i < 16; i++)
    {
        unsigned short x1 = (x & (1 << i));
        unsigned short y1 = (y & (1 << i));

        z |= (x1 << (i+1));
        z |= (y1 << i);
    }

    return z;
}

// You can use this function to print out the bit patterns
// for a given unsigned short. This should help in debugging.
char* short_to_binary(unsigned short x)
{
    static char b[17];
    b[0] = '\0';

    int z;
    for (z = 32768; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

// feel free to write any other helper functions you require
