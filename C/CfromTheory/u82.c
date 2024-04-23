/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void)
{
    int *ptr, i = 10, j = 20, k = 30;

    ptr = &i;
    *ptr = 40;

    ptr = &j;
    *ptr += i;

    ptr = &k;
    *ptr += i + j ;
    printf("%d %d %d\n", i, j, k); 
    return 0;
}