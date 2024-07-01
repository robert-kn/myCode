/* What is the output of the following program? */

#include <stdio.h>

int main(void)
{
    int *ptr, i = 10;
    ptr = &i;
    i += 20;
    printf("%d\n", *ptr);
    return 0;
}

/* Answer: Since ptr points to the address of i, *ptr is equal to i. The statement i += 20;
makes i equal to 30, and the program outputs 30. */