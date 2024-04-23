/**
 * What is the output of the following program?
*/

#include <stdio.h> 

int main(void)
{
    int *ptr, i, j = 1, a[] = {j, j+1, j+2, j+3};

    for(i = 0; i < 3; i++)
    {
        ptr = a+i;
        printf("%d ", a[*ptr]);
    }
    return 0;
}