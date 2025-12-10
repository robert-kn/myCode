// Write code for a function with the following prototype:

/*
 * Do rotating left shift. Assume 0 <= n < w
 * Examples when x = 0x12345678 and w = 32:
 * n=4 -> 0x23456781, n=20 -> 0x67812345
 */

 #include <stdio.h>

// Your function should follow the bit-level integer coding rules. Be careful of the case n = 0.

unsigned rotate_left(unsigned x, int n)
{
    int w = sizeof(int) << 3;
    int rshift = (w - n) & (w - 1);  /* prevent illegal shift by 32 */
    return (x << n) | (x >> rshift);
}

// rotate_left(x,n) = (x << n) | (x >> (32 - n)) OR-ing the pieces puts them together. we can’t we do x >> (32 - n) because if n is 0 then (32 - n) = 32 and you already know that x >> 32 is illegal. we we avoid shifting by 32 by use of the term (32 - n) & 31 

int main(void)
{
    int x = 0x12345678;
    printf("0x%.2X\n", rotate_left(x, 20));
    return 0;
}