/**
 * problem 2.59
 * 
 * Write a C expression that will yield a word consisting of the least significant byte of x, 
 * and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, this would give 
 * 0x765432EF.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){

    u_int32_t x = 0x89ABCDEF;
    u_int32_t y = 0x76543210; 
    
    int combine_bytes = (x & 0xff) | (y & 0xffffff00);
    printf("%.2X\n", combine_bytes);
    exit(EXIT_SUCCESS);
}