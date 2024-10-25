/**
 * problem 2.59
 * 
 * Write a C expression that will yield a word consisting of the least significant byte of x, 
 * and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, this would give 
 * 0x765432EF.
*/

#include <stdio.h>

int main(){

    int x = 0x89ABCDEF;
    int y = 0x76543210; 
    //int lsb_byte = x & 0xff; // grab the lowest significant byte of  the word  i.e. 0xef
    //int three_bytes = y & 0xffffff00; //  grab all bytes except the lowest significant byte i.e. 0x765432
    int combine_bytes = (x & 0xff) | (y & 0xffffff00);
    printf("%.2x\n", combine_bytes);
}