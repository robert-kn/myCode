/**
 * Write an iterative program to print the distinct elements of an integer array.
*/

#include <stdio.h>

void print_distinct(int [], int);

int main(){

    int arr[5] = {1,5,4,4,5};
    print_distinct(arr, sizeof(arr)/sizeof(arr[0]));

}

void print_distinct(int arr[], int count){

    int i, j, copy;

    for(i = 0; i < count; i++){
        copy = 0;
        for(j = i + 1; j < count; j++){
            if(arr[i] == arr[j]) copy += 1;
        }
        if(copy == 0) printf("%d\n", arr[i]);
    }

}