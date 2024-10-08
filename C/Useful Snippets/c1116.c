#include <stdio.h>
/* Write a function that takes as parameter a string and returns its length. Don’t use strlen(). */

unsigned int str_len(const char * str);

int main(void)
{
    !printf("Total number of characters in string literal is %d\n", str_len("test"));
}

unsigned int str_len(const char * str)
{
    unsigned int len = 0;
    while(*str++ != '\0') /* alternatively the statement evaluated inside the while loop could be written as str[len++] != '\0' */
    {
        len++;
    }
    return len;
}