/**
 * Suppose we number the bytes in a w-bit word from 0 (least significant) to w/8 – 1 (most significant). Write code for the following C function, which will return an unsigned value in which byte i of argument x has been replaced by byte b:
 * “unsigned replace_byte (unsigned x, int i, unsigned char b);
 * 
 * Here are some examples showing how the function should work:
 * replace_byte(0x12345678, 2, 0xAB) --> 0x12AB5678
 * replace_byte(0x12345678, 0, 0xAB) --> 0x123456AB
 */
#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    unsigned i;
    for(i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

unsigned int replace_byte(unsigned int x, int i, unsigned char b)
{
   unsigned int shift = i*8;
   unsigned mask = 0xFFu << shift;
   return (x & ~mask) | (b << shift);
}

int main(void)
{
    unsigned int x = 0x12345678;
    unsigned char b = 0xAB;
    unsigned int i = 0;
    unsigned int answer = replace_byte(x, i, b);
    show_bytes((byte_pointer) &answer, sizeof(x));
    return 0;
}

