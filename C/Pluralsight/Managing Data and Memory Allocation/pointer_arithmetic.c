#include <stdlib.h>
#include <stdio.h>

int main(int argc, char * argv[]){
    int count = 4;
    int * my_ptr = (int *) malloc(count * sizeof(int));

    int i;

    // simple pointer addition. notice how the addresses printed in the console are not incremented by 1 but by the 
    // total number of bytes used by an int data type
    for(i = 0; i < count; i++){
        printf("'my_ptr' address: %p\n", my_ptr + i);
    }

    int initial_value = 5;
    for(i = 0; i < count; i++){
        // assigning values to memory addresses using pointer arithmetic
        *(my_ptr + i) = initial_value++;

        // dereferencing pointers using pointer arithmetic
        printf("'my_ptr' position %d value: %d\n", i, *(my_ptr + i));
    }

    // easy to offset pointer address 
    int * my_other_ptr = (int *) malloc(count * sizeof(int));

    printf("\nStarting address of malloc'd block: %p\n", my_other_ptr);

    for(i = 0; i < count; i++){
        printf("'my_other_ptr' address: %p\n", my_other_ptr++); // accidentally incrementing pointer variable. This will
                                                                // lead to memory leaks 
    }

    printf("Starting address of malloc'd block has now changed: %p\n", my_other_ptr);

    free(my_ptr);
    free(my_other_ptr);

    return 0;
}