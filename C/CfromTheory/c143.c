/* Write a function that resizes a dynamically allocated memory that stores integers. The function takes as parameters a pointer to the original memory, the initial memory size, and the new 
size and returns a pointer to the new memory. The existing data should be copied in the new memory. Write a program that allocates memory dynamically to store an array of 10 integers and sets 
the values 100 up to 109 to its elements. Then, the pro- gram should call the function to reallocate new memory to store 20 integers and display its content.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *realloc_mem(int *ptr, int old_size, int new_size);

int main(void)
{
    int *arr, i;

    /* Allocate memory for 10 integers. */
    arr = (int*) malloc(10 * sizeof(int));
    if(arr == NULL)
    {
        printf("Error: Not available memory\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < 10; i++) 
        arr[i] = i+100;
    
    arr = realloc_mem(arr, 10, 20); /* arr points to the new memory. */

    printf("\n***** Array elements *****\n");
    for(i = 0; i < 20; i++)
        printf("%d\n", arr[i]);
    
    free(arr); /* Release new memory. */
    return 0;
}

int *realloc_mem(int *old_mem, int old_size, int new_size)
{
    int *new_mem;

    /* Allocate memory for new_size integers. */
    new_mem = (int*) malloc(new_size * sizeof(int));
    if(new_mem == NULL)
    {
        printf("Error: Not available memory\n");
        exit(EXIT_FAILURE);
    }
    /* Copy the existing data to the new memory. */
    memcpy(new_mem, old_mem, old_size * sizeof(int));
    free(old_mem); /* Release old memory. */
    return new_mem; /* Return the pointer to the new memory. */
}

/* The program displays the values 100–109 for the frst 10 elements and ran- dom values for the next ten, since they are not initialized. C library provides a function similar to 
realloc_mem(), called realloc(). realloc() is declared in stdlib.h and it is used to modify the size of a dynamically allocated memory. A short description is provided in Appendix C. */