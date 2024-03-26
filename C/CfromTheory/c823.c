/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void)
{
    int *ptr1, *ptr2, i = 10, j = 20;

    ptr1 = &i;
    *ptr1 = 150;

    ptr2 = &j;
    *ptr2 = 50;

    ptr2 = ptr1;
    *ptr2 = 250;

    ptr1 = ptr2;
    *ptr1 += *ptr2;
    printf("%d\n", i+j);
    return 0;
}

