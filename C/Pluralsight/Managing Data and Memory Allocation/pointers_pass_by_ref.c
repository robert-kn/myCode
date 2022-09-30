#include <stdio.h>
#include <stdlib.h>

void print_int_by_reference(int * number_ptr);
void print_int_by_value(int number);

void malloc_int_dangerous(int * number_ptr);
void malloc_int_safe(int ** number_ptr);

int main(int argc, char * argv[]){
    // example of passing an int via a pointer instead of by value
    int my_number = 10;

    print_int_by_value(my_number);

    print_int_by_reference(&my_number);

    printf("The addresses printed above should be different!\n\n\n");

    int * number_ptr = &my_number;

    printf("'number_ptr' address before malloc: %p\n", number_ptr);

    // create a function that takes in a pointer to an int, attempts to malloc memory for it and return the pointer -
    // this will not work (memory leak will occur because the pointer passed in points to memory on the stack)
    malloc_int_dangerous(number_ptr);

    printf("Original 'number ptr' address after dangerous malloc: %p\n", number_ptr);
    printf("The above address for 'number_ptr' does not change!\n");

    // create a function that takes in a double pointer to an int and malloc memory to the dereferenced double pointer
    malloc_int_safe(&number_ptr); // pass the address of the 'number_ptr' pointer

    printf("'number_ptr' address after safe malloc: %p\n", number_ptr);

    free(number_ptr);

    number_ptr = NULL;

    return 0;

}

// takes an integer and prints it to the console
void print_int_by_reference(int * number_ptr){
    printf("Printing Int =>> Address: %p | Value: %d\n", number_ptr, *number_ptr);
}

// the 'number' argument below is copied into the function scope
void print_int_by_value(int number){
    printf("Printing Int ==> Address: %p | Value %d\n", &number, number);
}

// this will not work and will result in a memory leak because 'number_ptr' is passed by value.
void malloc_int_dangerous(int * number_ptr){
    number_ptr = (int *) malloc(sizeof(int));
    printf("[malloc_int_dangerous] => 'number_ptr' address after dangerous malloc: %p\n", number_ptr);
    printf("[malloc_int_dangerous] => ^^ That address space marks a memory leaked block!\n\n");
    // 'number_ptr' now goes out of scope and you have a memory leak
}


// this will work without causing any issues as long as the allocated memory is freed up aftwerwards
void malloc_int_safe(int ** number_ptr){
    * number_ptr = (int *) malloc(sizeof(int));
}