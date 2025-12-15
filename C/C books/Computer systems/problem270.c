// Write code for the function with the following prototype:
#include <stdio.h>
/*
 * Return 1 when x can be represented as an n-bit, 2's-complement
 * number; 0 otherwise
 * Assume 1 <= n <= w
 */
int fits_bits(int x, int n);

// Your function should follow the bit-level integer coding rules.

// A value fits in n-bit 2's complement exactly when:

// -2^(n-1)  ≤ x ≤  2^(n-1) - 1

// Example: Does x = 100 fit in n = 7 bits? 7-bit range is -64 to +63. 100 does NOT fit → return 0

// Key idea: If a number fits in n bits, then its top (32-n) bits must all be copies of its sign bit.

int main(void)
{
    int x = 60;
    int n = 7;
    printf("%d\n", fits_bits(x, n));
    return 0;
}

int fits_bits(int x, int n)
{
    int shift = 32 - n;
    return x == (x << shift >> shift);
}