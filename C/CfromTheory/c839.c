/**
 * Use the p pointer and complete the following program to create an identity 5×5 matrix. In math, an identity matrix has 1’s on the main diagonal’s elements and 0s everywhere else.
*/

#include <stdio.h>

#define SIZE 5

int main(void)
{
    int *p, arr[SIZE][SIZE] = {0};

    for(p = &arr[0][0]; p <= &arr[SIZE-1][SIZE-1]; p++)
    {
        if((p-&arr[0][0])%(SIZE+1) == 0)
            *p = 1;
    }
    return 0;
}

/**
 * 
 * Comments: Since the elements of the array are initialized with 0, it is sufficient to make the elements of the main diagonal equal to 1. The if condition checks if the element belongs to the diagonal. The form of that condition is 
 * based on the observation that the number of elements between two successive diagonal’s elements is SIZE. For example, in the 5×5 array, the elements of the diagonal are in positions 0, 6, 12, 18, and 24. Also, with this example, we 
 * want to show you that it is perfectly legal to treat two-dimensional array as if it were one-dimensional. We exploit the fact that the elements are stored in successive positions in memory.
*/