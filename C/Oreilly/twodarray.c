/* twodarray.c
   purpose: show how to create a two dimensional array
   the size of the array is 8 rows * 3 columns
*/

#include <stdio.h>
#include <stdlib.h>

#define NUMROW 8
#define NUMCOLUMN 3

int main(int argc, char * * argv)
{
    int * * arr2d;
    int row;
    /* step 1: create an array of integer pointers*/

    arr2d =  malloc(NUMROW * sizeof(int *));

    for(row = 0; row < NUMROW; row++)
    {
        /* step 2: for each row (i.e. integer pointer), create an integer array */
        * (arr2d + row) = malloc(NUMCOLUMN * sizeof(int));
    }

    /* now, the two dimensional array can be used */
    arr2d[4][1] = 6;
    arr2d[6][0] = 19;

    /* the first index can be 0  to 7 (inclusive) */
    /* the second index can be 0 to 2 (includive) */

    /* the memory must be released in reverse order */
    for(row = 0;  row < NUMROW; row++)
    {
        /* release the memory for each row frst */
        free(arr2d[row]);
    }

    /* now release the array of integer pointers */
    free(arr2d);
    return EXIT_SUCCESS;
}