/**
 * Write a procedure is_little_endian that will return 1 when compiled and run on a little-endian machine, and will return 0 when compiled and run on a big-endian machine. This program should run on any machine, regardless of its word size.
 */

#include <stdint.h>
#include <stdio.h>

typedef unsigned char * byte_pointer;

int is_little_endian(void)
{
    uint16_t x = 0x0001;
    return *((byte_pointer) &x) == 0x01;
}

int main(void)
{
    printf("%d\n", is_little_endian());
    return 0;
}