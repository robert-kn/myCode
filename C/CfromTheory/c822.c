/**
 * Use the ptr pointer and complete the following program to read and store the grades of 50 students into arr and then display the 
 * array’s values in reverse order. Use pointer arithmetic to process the array.
 * 
*/

#include <stdio.h>

#define SIZE 50

int main(void){
    float *ptr, arr[SIZE];

    for(ptr = arr; ptr < arr+SIZE; ptr++){
        printf("Enter grade: ");
        scanf("%f", ptr);
    }

    for(; ptr >= arr; ptr--)
        printf("%f ", *ptr);
    printf("\n");
    return 0;
}