/**
 * What is the output of the following program?
*/

#include <stdio.h> 
#include <string.h>

int main(void)
{
    char str[10] = {0};
    printf("%c\n", *(str+strlen(strncpy(str, "example", 5))/2));
    return 0;
}

/**
 * Answer: strncpy() copies the first five characters into str. The return value of strncpy(), that is, the pointer to str is used as 
 * the argument of strlen(). Therefore, strlen() returns the length of the string stored into str, that is, 5. As a result, printf() 
 * is translated to printf("%c\n", *(str+5/2)); and the program displays the character stored in position str+2, that is, a.
 * 
*/