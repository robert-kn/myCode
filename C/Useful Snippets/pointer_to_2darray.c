#include <stdio.h>

int main(void)
{
    int i, j, a[2][3];

    int (*p)[3]; /* pointer to an array of 2 arrays where each array comprises 3 elements */
    p = a;      /* points to a[0][0] */
    p++;        /* points to a[1][0] */

    for(i = 0; i < 2; i++)
        for(j = 0; j < 3; j++)
            /* printf("Addr[%d][%d]: %p\n", i, j, &a[i][j]); */
            /* printf("Addr[%d][%d]: %p\n", i, j, (a[i]+j)); */
            printf("Addr[%d][%d]: %p\n", i, j, (*(a+i)+j));
    return 0; 
}