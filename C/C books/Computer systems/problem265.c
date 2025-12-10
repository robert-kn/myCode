/**
 * Write code to implement the following function
 * 
 * Your function should follow the bit-level integer coding rules (page 120), except that you may assume that data type int has w = 32 bits. Your code should contain a total of at most 12 arithmetic, bit-wise, and logical operations.
*/

/* Return 1 when x contains an odd number of 1s; 0 otherwise. Assume w=32. */

#include <stdio.h>

int odd_ones(unsigned x)
{
    x ^= x >> 16; /* parity info for the whole 32 bits */
    x ^= x >> 8;  /* parity info for the whole 16 bits */
    x ^= x >> 4;  /* parity info for the whole 8 bits */
    x ^= x >> 2;  /* parity info for the whole 4 bits */
    x ^= x >> 1;  /* parity info for the whole 2 bits */
    return x & 1;
}

int main(void)
{
    unsigned x = 0xaaaaaaaau;
    printf("is there an odd number of ones? %s\n", odd_ones(x)? "true": "false");
    return 0;
}
/**
 * explanation: XOR is 1 only when an odd number of bits are 1. it acts like an add without a carry. if we XOR all bits of x together, the final result is 1 if there is an odd number of bits. this is the definition of parity. Each XOR “fold” mixes together pairs of bits so that eventually every bit in the number has been XORed into the lowest bit. At the end, that one bit (the rightmost one) tells us the overall parity (odd/even number of 1s). e.g. x = 1011 then 1 ^ 0 ^ 1 ^ 1 = 1 (because there’s an odd number of 1s). We can't loop (loops aren't allowed by the assignment), so instead we fold the number onto itself using right shifts.
 */
