#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ARRAY_SIZE 4

typedef struct person {
    int age;
    int id;
} Person;

int main(int argc, char * argv[]){
    // declare and initialise array
    int numbers[] = {1, 2, 3, 4};

    const double floats[] = {1.23, 1.45, 1.67, 1.99};

    const char name[] = "Robert";

    const Person people[] = {
        {47, 1},
        {35, 2}
    };

    // looping over array members using array notation
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("\nNumber: %d\n",numbers[i]);
        numbers[i] += 2;
    }

    // array names 'decay' to pointers
    assert(numbers == &numbers[0]);

    printf("\nStarting address of the 'numbers' array by array name: %p\n", numbers);
    printf("\nStarting address of the 'numbers' array by pointer to the first element: %p\n\n", &numbers[0]);

    return 0;
}

