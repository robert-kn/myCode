/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void)
{
    char str1[] = "test", str2[] = "test";

    (str1 == str2)? printf("One\n") : printf("Two\n");
    printf("%p %p\n", str1, str2);
    return 0;
}

/**
 * Answer: Since the names of the two arrays are used as pointers, the expression str1 == str2 checks if the pointers point to the same address, not if the arrays are the same. Do str1 and str2 point to the same address?
 * Of course not; str1 and str2 have the same content, but they are stored in different memory. Therefore, the program displays Two.
 * 
 * What would be the output if we write:
 * (*str1 == *str2) ? printf("One\n") : printf("Two\n");
 * 
 * Since str1 can be used as a pointer to its first element, *str1 is equal to 't'. Similarly, *str2 is equal to 't'. Therefore, the program would display One.
*/