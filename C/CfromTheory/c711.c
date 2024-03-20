/**
 * Write a program that reads 20 integers and stores them in two arrays of 10 elements each. Then, the program should check if the two arrays have common elements, and if yes, the program should display the value 
 * of each common element and its position in both arrays. Otherwise, it should display a message that their elements are different.
*/

#include <stdio.h>

#define SIZE 10

int main(void){
    int arr1[SIZE], arr2[SIZE], i, j, found = 0;

    for(i = 0; i <  SIZE; i++){
        printf("Enter arr1[%i] element: ", i);
        scanf("%d", &arr1[i]);
    }

    for(i = 0; i <  SIZE; i++){
        printf("Enter arr2[%i] element: ", i);
        scanf("%d", &arr2[i]);
    }

    for(i = 0; i <  SIZE; i++){
        for(j = 0; j < SIZE; j++){
            if(arr1[i] == arr2[j]){
                found = 1;
                printf("arr1[%i] element is %i and arr2[%i] element is %i\n", i, arr1[i], j, arr2[j]);
            }
        }
    }

    if(found)
        printf("Similar elements found\n");
    else
        printf("Elements are different\n");
    
}