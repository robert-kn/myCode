/**
 * Write a procedure is_little_endian that will return 1 when compiled and run on a little-endian machine, and will return 0 when compiled and run on a big-endian machine. This program should run on any machine, regardless of its word size.
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

int is_little_endian(void)
{
    uint16_t x = 0x0001;
    return *((byte_pointer) &x) == 0x01;
}

int main(void)
{
    // const uint16_t x = 0x0001;
    // show_bytes((byte_pointer) &x, sizeof(x));
    printf("%d\n", is_little_endian());
    return 0;
}