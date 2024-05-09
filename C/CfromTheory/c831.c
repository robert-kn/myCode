/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void){
    int *p[3], i, arr[4] = {10, 20, 30, 40};

    for(i = 0; i < 3; i++)
    {
        p[i] = &arr[i]+1; /* what is the order in which the operators are applied? */
        printf("%d ", *p[i]);
    }
    return 0;
}

/**
 * Answer: The statement p[i] = &arr[i]+1; makes each element of p point to the address of the next element after arr[i]. Therefore, when i is 0, p[0] points to arr[1], when it is 1, p[1] points to arr[2], and when it is 2, p[2] points 
 * to arr[3]. Therefore, the program displays:20 30 40.
*/