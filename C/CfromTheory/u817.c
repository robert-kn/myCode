/**
 * What does the following program do?
*/

#include <stdio.h>

#define COLS 4

int main(void)
{
    int i, arr[][COLS] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160};

    for(i = 0; i < COLS; i++)
        *(arr[i]+i) = *(arr[i]+COLS-1-i) = 0;

    return 0;
}