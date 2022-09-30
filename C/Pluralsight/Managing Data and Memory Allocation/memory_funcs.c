#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
    int number_count = 4;

    // Allocate a block of memory in the heap for 4 integer values using malloc
    int * number_ptr = (int *) malloc(number_count * sizeof(int));

    // looping through the integer pointer
    for(int i = 0; i < number_count; i++){
        *(number_ptr + i) = i;
        printf("Added value %d to address %p\n", i, number_ptr + i);
    }


    printf("\n\n");

    // Allocating a block of memory in the heap and fill it with zeroes 
    int * calloc_number_ptr = (int *) calloc(number_count, sizeof(int));

    printf("Address of calloc block of memory: %p\n", calloc_number_ptr);

    for(int i = 0; i < number_count; i++){
        printf("Value in calloc memory addresses should be 0: %d\n", *(calloc_number_ptr + i));
    }

    printf("\n\n");


    // Resizing allocated memory in the heap using realloc
    number_ptr = (int *) realloc(number_ptr, (number_count + 2) * sizeof(int));

    printf("Show the values of stored in the resized block of memory\n");

    for(int i = 0; i < number_count + 2; i++){
        if(i == number_count || i == number_count + 1){
            *(number_ptr + i) = i;
        }
        printf("Value in reallocated block: %d\n", *(number_ptr + i));
    }

    // Free heap memory that was allocated in order to avoid memory leaks
    free(number_ptr);
    free(calloc_number_ptr);
}