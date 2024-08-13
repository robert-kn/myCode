/**
 * Write a program that reads 10 integers and stores them in an array. Then, the program 
 * should check if the array is symmetric, 
 * that is, if the value of the first element is equal to the last one, the value of the 
 * second one is equal to the value of the last but one, and so on.
*/

#include <stdio.h>

#define SIZE 10

int main(void){
    int arr[SIZE], i, j;

    for(i = 0; i < SIZE; i++){
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    for(i = 0, j = 9; i < j; i++, j--)
        if(arr[i] == arr[j])
            continue;
        else{
            printf("Not symmetric\n");
            return 1;
        }
    printf("Symmetric array\n");        
    return 0;
}