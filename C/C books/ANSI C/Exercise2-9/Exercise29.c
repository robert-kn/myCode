#include <stdio.h>
/* In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit
in x. Explain why. Use this observation to write a faster version of bitcount.
*/

/*
Because when x is expanded to its bit format, x - 1 results in least significant bit set to one being taken away
from the bit pattern and when an & operation is used along with the original number, it results in a 
mask that has the rightmost 1 bit deleted. Repeating this process will eventually result in the number totalling zero.
*/

int bitcount(unsigned x){
    int b;

    for(b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}

int main(){
    unsigned int num = 0x777;
    printf("Number of 1  bits in the argument is %d\n", bitcount(num));
}