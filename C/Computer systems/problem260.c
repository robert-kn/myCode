/**
 * Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 − 1 (most significant). Write code 
 * for the following C function, which will return an unsigned value in which byte i of argument x has been replaced 
 * by byte b:
 * 
 * unsigned replace_byte (unsigned x, int i, unsigned char b);
 * 
 * Here are some examples showing how the function should work:
 *      replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 *      replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
*/

/**
 *  Algorithm to solve the problem:
 *      1. left shift byte i by the required amount; in this case by 8 (or you can multiply i by 8)
 *      2. calculate the mask that will be used to set the target bits all to zero by left shifting the byte 0xff 
 *         with the value from step 1
 *      3. complement the mask and use the bitwise operator & to set the target bits to zero whilst maintaining all
 *         other bits.
 *      4. left shift the replacement byte by the calculated amount in step 1 and then use the bitwise operator | to 
 *         substitute the replacement byte
*/

#include <stdio.h> 

unsigned replace_byte(unsigned, int, unsigned char);

int main(){

    printf("replace_byte(0x12345678, 2, 0xAB) --> %x\n", replace_byte(0x12345678, 2, 0xAB));
    printf("replace_byte(0x12345678, 0, 0xAB) --> %x\n", replace_byte(0x12345678, 0, 0xAB));

}

unsigned replace_byte(unsigned x, int i, unsigned char b){

    int i_times_8 = i << 3;
    unsigned mask = 0xFF << i_times_8; 
    return (x & ~mask) | (b << i_times_8);

}

