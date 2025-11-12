#include <stdio.h>

int int_shifts_are_arithmetic(void)
{
    int x = -1;
    return (x >> 1) == x;
}

int main(void)
{
    printf("%d\n", int_shifts_are_arithmetic());
    return 0;
}