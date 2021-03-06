#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "part4.h"

/*
 * Implement the C function called part4_opt. It should perform
 * the same task as the implemented part4 function. In the
 * comments for the function describe why your changes make the
 * function more cache friendly.
 * 
 * Note: your function needs to compute the entire matrix C, not only C[x]. 
 */

//Luis Olivar lao294

long part4(long* B, long* A, int x) {
    long* C = (long*) calloc(N, sizeof(long));
    if (!C) return 0; 
    
    int c, r; 
    for(c = 0; c < N; c++)
        for(r = 0; r < N; r++)
            C[r] = B[r * N + c] + A[c * N + r];
    
    long ret = C[x];
    free(C); 
    return ret;
}

long part4_opt(long* B, long* A, int x) {
    long* C = (long*) calloc(N, sizeof(long));
    if (!C) return 0; 

    //by allowing c to take the value of r from the start, we avoid having 
    //to refer to two seperate values that are essentially identical.
    int c, r; 
    for(r = 0; r < N; r++)
        for(c = r; c < N; c++)
            C[r] = A[c * N + r] + B[r * N + c];
    
    //DO NOT modify the rest of this function 
    long ret = C[x];
    free(C); 
    return ret;
}
