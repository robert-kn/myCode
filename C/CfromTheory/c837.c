/**
 * What does the following program do?
*/

#include <stdio.h>

int main(void)
{
    int *ptr, arr[2][5] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for(ptr = arr[1]+2; ptr < arr[1]+5; ptr++)
        *ptr = 0;

    return 0;
}

/**
 * 
 * Answer: The statement ptr = arr[1]+2; makes ptr point to the address of arr[1][2]. Since *ptr is equal to arr[1][2], the statement *ptr = 0; is equivalent to arr[1][2] = 0;. The statement ptr++; makes ptr point to the next element of 
 * the current row. For example, when ptr is first increased, it points to the address of arr[1][3] and the next increment makes it point to the address of arr[1][4]. Therefore, the program makes zero the last three elements of the second 
 * row.
 * 
*/