#include <stdio.h>
#include <assert.h>

/* Luis Olivar, lao294@nyu.edu, 02/28/2017*/

// Extract the 8-bit exponent field of single precision
// floating point number f and return it as an unsigned byte
unsigned char get_exponent_field(float f)
{
    // cast float into unsigned int pointer in order to be able to and it
    // with the mask which is set to the highest unsigned int value (all 1s).
    unsigned int mask = 0xffffffff;
    unsigned int* ptr = (unsigned int*)&f;
    unsigned int e = *ptr & mask;
    e >>= 23;
    // assert(0);
    // since e is always going to be at most 8bits,
    // this cast is not necessary, but peace of mind is nice.
    return (unsigned char)e;
}

// Clear the most significant b bits of unsigned integer number
// and return the resulting value.
// As an example, suppose
//   unsigned int number = 0xffff0000;
//   int b = 15;
// then the correct return value is 65536
// if b = 30, then the return value is 0
// if b = 40, the return value should also be 0
unsigned int clear_msb(unsigned int number, int b)
{
    if(b == 0)
        return number;

    //Take advantage of unsigned ints lack of preserving first bit for sign purposes
    number <<= b;
    number >>= b;

    return number;
}

// Given an array of bytes whose length is array_size (bytes), treat it as a bitmap (i.e. an array of bits),
// and return the bit value at index i (from the left) of the bitmap.
//
// As an example, suppose char array[3] = {0x00, 0x1f, 0x12}, the corresponding
// bitmap is 0x001f12, thus,
// the bit at index 0 is bitmap[0] = 0
// the bit at index 1 is bitmap[1] = 0
// ...
// the bit at index 11 is bitmap[11] = 1
// the bit at index 12 is bitmap[12] = 1
// ...
// the bit at index 16 is bitmap[16] = 0
// ...
unsigned char bit_at_index(unsigned char *array, int array_size, int i)
{
    // The index we must look in for the char array is going to be the index of the bit we are
    // looking for divided by the size of a 2 digit hex number (8 bytes).

    // Use integer division
    int indexToSearch = i/8;
    unsigned int hexIndex = array[indexToSearch];
    // Find the 1 of the 8 bits we are checking
    int subBit = i - (8 * indexToSearch);
    unsigned char answer;
    // Use a mask 1000-0000
    unsigned char mask = 128;
    if(hexIndex & (mask >> subBit))
        return 1;
    else
        return 0;
}
