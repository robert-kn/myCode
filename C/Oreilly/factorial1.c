#include <stdio.h>

long int fac(int n)
{
    if(n < 0)
    {
        printf("n cannot be negative\n");
        return 0;
    }

    if(n == 0)
    {
        return 1;
    }

    return n * fac(n - 1);
}