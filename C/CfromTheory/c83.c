/* The following program uses a pointer to read and display a float number. Is there
any programming bug? */

#include <stdio.h>

int main(void)
{
    double *ptr, i;
    scanf("%lf", ptr);
    printf("Val = %f\n", *ptr);
    return 0;
}

/* Answer: The code is wrong because ptr does not point to the address of i, before being
used in scanf(). Had we added the statement ptr = &i; before scanf(), the program
would be executed normally. */