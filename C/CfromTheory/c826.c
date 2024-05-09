/**
 * Use the p1 and p2 pointers and complete the following program to read and store 50 integers into arr1 and arr2, respectively. Then, 
 * the program should display the values of the common elements and their positions in the two arrays, if found. Use pointer arithmetic 
 * to process the arrays.
*/

#include <stdio.h>

#define SIZE 50

int main(void)
{
    int *p1, *p2, arr1[SIZE], arr2[SIZE];

    p1 = arr1;

    for(; p1 < arr1+SIZE; p1++){
        printf("Enter number: ");
        scanf("%d", p1);
    }
    printf("\nSecond array\n");
    for(p2 = arr2; p2 < arr2+SIZE; p2++){
        printf("Enter number: ");
        scanf("%d", p2);
    }

    for(p1 = arr1; p1 < arr1+SIZE; p1++){
        for(p2 = arr2; p2 < arr2+SIZE; p2++){
            if(*p1 == *p2)
                printf("Common element:%d found in positions %d and %d\n", *p1, p1-arr1+1, p2-arr2+1);
        }
    }
    return 0;
}