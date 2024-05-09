/**
 * What is the output of the following program?
*/

#include <stdio.h> 
#include <string.h>

int main(void)
{
    char str1[5], str2[5];

    printf("%c\n", strcpy(str1, strcpy(str2, "test"))[0]);
    return 0;
}

/**
 * Answer: The inner strcpy() copies the string test into str2 and returns a pointer to str2. The outer strcpy() copies the string 
 * pointed to by the returned pointer of the inner strcpy() into str1. Therefore, the string test is copied into str1. Since the outer 
 * strcpy() returns a pointer to str1, printf() is translated to printf("%c\n", str1[0]); and the program displays t.
*/