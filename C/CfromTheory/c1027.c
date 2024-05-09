/**
 * What is the output of the following program?
*/

#include <stdio.h> 
#include <string.h>

int main(void)
{
    char str[] = "test";
    printf("%d %s\n", *strcpy(str, "n")**strcpy(str+2, "xt"), str);
    return 0;
}

/**
 * Answer: The first strcpy() copies the characters of the string "n", that is, the characters 'n' and '\0' to str[0] and str[1], 
 * respectively, and returns a pointer to str. Therefore, the expression *strcpy(str, "n") can be replaced by *str, that is, 'n'. 
 * The second strcpy() copies the string "xt" in the third position of str and returns the str+2 pointer. Therefore, the expression 
 * *strcpy(str+2, "xt") can be replaced by *(str+2), that is, 'x'.
 * 
 * As a result, the program displays the product of the ASCII codes of 'n' and 'x', that is, 13200. However, it does not display next as 
 * you might expect, but just n, because the first strcpy() replaced 'e' with '\0'.
*/