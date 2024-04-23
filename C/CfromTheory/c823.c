/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void)
{
    int *ptr1, *ptr2, i = 10, j = 20;

    ptr1 = &i;
    *ptr1 = 150;
    printf("I am i and should be 150. i have value %d and address %p\n", *ptr1, ptr1);

    ptr2 = &j;
    *ptr2 = 50;
    printf("I am j and should be 50 have value %d and address %p\n", *ptr2, ptr2);

    ptr2 = ptr1;
    *ptr2 = 250;
    printf("i address %p and value is %d, j address %p and value is %d\n", ptr1, *ptr1, ptr2, *ptr2);
    printf("i value %d, j value %d\n", i, j);

    ptr1 = ptr2;
    *ptr1 += *ptr2;
    printf("%d\n", i+j);
    return 0;
}

