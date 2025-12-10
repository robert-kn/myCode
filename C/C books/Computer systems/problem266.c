/**
 * write code to implement the following function
 * 
 * Generate mask indicating leftmost 1 in x. Assume w=32.
 * For example 0xFF00 -> 0x8000, and 0x6600 --> 0x4000.
 * If x = 0, then return 0.
 * 
 * Your function should follow the bit-level integer coding rules (page 120), except that you may assume that data type int has w = 32 bits.
 * 
 * Your code should contain a total of at most 15 arithmetic, bit-wise, and logical operations.
 * 
 * Hint: First transform x into a bit vector of the form [0 . . . 011 . . . 1].
*/

#include <stdio.h>


int leftmost_one(unsigned x){
    
    unsigned int spread = x;
    spread |= spread >> 1;
    spread |= spread >> 2;
    spread |= spread >> 4;
    spread |= spread >> 8;
    spread |= spread >> 16;
    return spread & ~(spread >> 1);
}

int main(){
    int x = 0x6600;
    printf("0x%.2x\n", leftmost_one(x));
}
