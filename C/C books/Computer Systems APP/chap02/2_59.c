/**
 * Write a C expression that will yield a word consisting of the least significant byte of x and the remaining bytes of y. For operands x = 0x89ABCDEF and y = 0x76543210, this would give 0x765432EF.
 */

#include <stdint.h>
#include <stdio.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    unsigned i;
    for(i = 0; i < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

int main(void)
{
    u_int32_t x = 0x89ABCDEF;
    u_int32_t y = 0x76543210;

    u_int32_t masked_x = x & 0xFF;
    u_int32_t masked_y = y & 0xffffff00;
    u_int32_t combine_bytes = masked_x | masked_y;
    printf("%.2x\n", combine_bytes);
    return exit(EXIT_SUCCESS);
}