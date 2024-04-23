/**
 * What does the following program do?
*/

#include <stdio.h>

int main(void)
{
    int i, arr[2][5] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for(i = 0; i < 2; i++)
        *(arr[i]+3) = 0;
    return 0;
}

/**
 * Answer: In each iteration, arr[i] points to the first element of row i. The expression arr[i]+3 is a pointer to the fourth element of row i. Therefore, *(arr[i]+3) is equal to arr[i][3]. As a result, the program makes zero the 
 * elements of the fourth column, so, arr[0][3] and arr[1][3] become 0.
 * 
*/