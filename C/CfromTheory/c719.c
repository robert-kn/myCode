/**
 * Write a program that reads 100 integers and stores them in an array. Then, the pro- gram should find and display the two different higher values.
*/

#include <stdio.h>

#define SIZE 100

int main(void){

    int i, highest, higher, arr[SIZE] = {0};
    highest = higher = 0;

    for(i = 0; i < SIZE; i++){
        printf("Enter integer %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < SIZE; i++){
        if(arr[i] > highest)
            highest = arr[i];
    }

    for(i = 0; i < SIZE; i++){
        if(arr[i] > higher && arr[i] != highest)
            higher = arr[i];
    }

    printf("Highest value in array is  %d and second highest is %d\n", highest,  higher);
    return 0;

}