/**
 * What is the output of the following program?
*/

#include <stdio.h> 

int main(void)
{
    int *ptr1, *ptr2, *ptr3, i = 10, j = 20, k = 30;

    ptr1 = &i;
    ptr2 = &j;
    ptr3 = &k;

    *ptr1 = *ptr2 = *ptr3;
    k = i+j; 
    printf("%d\n", *ptr3); 
    return 0;
}