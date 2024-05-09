/**
 * Write a program that declares an array of 10 integers and assigns random values within [5, 20] to its elements. Then, the program should check if the 
 * array contains duplicated values, and if yes, it should delete them. When an element is deleted, the next elements should be shifted one position to 
 * the left. The empty positions should be given the value -1. For example, if the array is {9, 12, 8, 12, 17, 8, 8, 19, 1, 19} it should become {9, 12, 8, 
 * 17, 19, 1, -1, -1, -1, -1}.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    int i, j, k, size, arr[SIZE];
    srand(time(NULL));
    
    for(i = 0; i < SIZE; i++)
        arr[i] = rand()%16+5;
    
    size = SIZE;
    for(i = 0; i < size; i++){
        j = i+1; 
        while(j < size)
        {
            if(arr[i] == arr[j]){
                for(k = j; k < size-1; k++)
                    arr[k] = arr[k+1]; /* Shift the elements one position to the left. */
                size--; /* Since the element is deleted, their number is decremented. */
            }
            else
                j++;
        }
    }

    for(i = size; i < SIZE; i++) 
        arr[i] = -1;
    for(i = 0; i < SIZE; i++) 
        printf("%d ", arr[i]);
    return 0;
}