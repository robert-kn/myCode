/**
 * Use the ptr pointer and complete the following program to read 50 integers and store into arr those with a value within [30, 40]. 
 * The program should display how many values are stored in the array. The program should set the value -1 to the remaining elements. 
 * Use pointer arithmetic to process the array.
*/

#include <stdio.h>

#define SIZE 50

int main(void){
    int *ptr, i, arr[SIZE];
    
    ptr = arr;
    for(i = 0; i < SIZE; i++){
        printf("Enter number: ");
        scanf("%d", ptr);

        if(*ptr >= 30 && *ptr <= 40)
            ptr++;
    }
    printf("%d elements are stored\n", ptr-arr);
    for(; ptr < arr+SIZE; ptr++)
        *ptr = -1; 
    return 0;
}