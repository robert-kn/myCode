//Write code for a function with the following prototype:
/*
 * Mask with least signficant n bits set to 1
 * Examples: n = 6 --> 0x2F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */

//Your function should follow the bit-level integer coding rules (page 120). Be careful of the case n = w.
#include <stdio.h>

int lower_one_mask(int n){
    int left_shift = 1 << n;
    return left_shift - 1;
    //return left_shift;
}

int main(){
    printf("0x%.2x\n", lower_one_mask(6));
    return 0;
}