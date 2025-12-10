//Write code for a function with the following prototype:
/*
 * Mask with least signficant n bits set to 1
 * Examples: n = 6 --> 0x3F, n = 17 --> 0x1FFFF
 * Assume 1 <= n <= w
 */

//Your function should follow the bit-level integer coding rules (page 120). Be careful of the case n = w.
#include <stdio.h>

int lower_one_mask(int n){
    int w = sizeof(int) << 3;
    return ((unsigned) -1) >> (w - n);
}

int main(){
    printf("0x%.2x\n", lower_one_mask(17));
    return 0;
}

/**
 * Key Trick

A mask of the lowest n bits = ((1 << n) – 1) 

BUT shifting by 32 is illegal (undefined behavior), so we must avoid:

1 << 32 // not allowed

So instead we compute:

((unsigned) -1) >> (w - n)

Why?

(unsigned) -1) or ~0 = all 1s

Shifting right clears the upper bits

Leaves exactly n lower bits as 1

For example, with w = 32:

n = 6:
~0 >> (32 - 6) = 0xFFFFFFFF >> 26 = 0x0000003F

n = 17:
~0 >> 15 = 0x0001FFFF

n = 32:
~0 >> 0 = 0xFFFFFFFF

Perfect — and no illegal shifts.
 */