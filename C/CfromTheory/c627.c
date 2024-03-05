/**
 * Find the number of iterations in the following program.
*/

#include <stdio.h> 
int main(void){
    int a = 256, b = 2;

    while(a != b){
        b = b*b;
        a >>= 2; 
    }
    return 0; 
}

/**
 * 1st iter --> 256 != 2 hence  b = 4, a = 256/2 = 128/2 = 64
 * 2nd iter --> 64 != 4 hence   b = 16, a = 64/2 = 32/2 = 16
 * 3rd iter --> 16 == 16
*/