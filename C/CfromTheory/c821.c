/**
 * Use the ptr pointer and an iteration loop and complete the following program to decrement the arr elements by one. The program 
 * should display their sum, before it terminates. Use pointer arithmetic to process the array.
*/

#include <stdio.h> 

int main(void){
    int *ptr, sum, arr[5] = {11, 21, 31, 41, 51};
    sum = 0;
    for(ptr = arr; ptr < arr+5; ptr++){
        --*ptr;
        sum += *ptr;
    }
    printf("Sum = %d\n", sum);
    return 0;
}