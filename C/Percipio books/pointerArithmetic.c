#include <stdio.h>

void main(){
    // an array is a pointer to the first object stored in the array
    int array[3] = {1, 2, 3};

    system("clear");

    printf("first index: %d second index: %d third index: %d\n", * array, * (array + 1), * (array + 2));
    printf("\n");
    printf("first index: %d second index: %d third index: %d\n", array[0], array[1], array[2]); // same result as above

    // assign a new value to the first object in the array
    * array = 10; 

    // assign a new value to the second object in the array
    * (array + 1) = 15;

    // assign a new value to the third object in the array
    * (array + 2) = 20;

    printf("\n");
    printf("\n");
    printf("\n");
    printf("first index: %d second index: %d third index: %d\n", array[0], array[1], array[2]);



}