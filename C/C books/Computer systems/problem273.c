// Write code for a function with the following prototype:

/* Addition that saturates to TMin or TMax */
#include <limits.h>
#include <stdio.h>

// Instead of overflowing the way normal two's-complement addition does, saturating addition returns TMax when there would be positive overflow, and TMin when there would be negative overflow. Saturating arithmetic is commonly used in programs that perform digital signal processing.
// Your function should follow the bit-level integer coding rules.

// Detect overflow: Overflow happens only if x and y have the same sign, AND s has a different sign than x

int saturating_add(int x, int y)
{
    int sum = x + y;

     /* sign masks: 0x00000000 for nonnegative, 0xFFFFFFFF for negative */
    int sx = x >> 31; 
    int sy = y >> 31; 
    int ss = sum >> 31;

    /* overflow if x,y same sign AND sum different sign than x */
    int overflow = (~(sx ^ sy)) & (ss ^ sx); /* 0xFFFFFFFF if overflow else 0 */
    
    /* value to return on overflow: INT_MAX if x>=0, INT_MIN if x<0 */
    int sat = (sx & INT_MIN) | (~sx & INT_MAX);

     /* select: overflow ? sat : sum */
    return (overflow & sat) | (~overflow & sum);
}

int main(void)
{
    printf("%d\n", saturating_add(2, 1));
    return 0;
}