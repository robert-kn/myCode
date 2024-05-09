/**
 * What is the output of the following program?
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Text";
    printf("%d %d\n", strlen(str+4), strlen("Text"+1));
    return 0;
}

/***
 * Answer: Since the name of an array can be used as a pointer to its first element—we do know that we’ve written it many times, we just 
 * want to be sure that you’ve got it—str+4 is a pointer to the fifth character of str, that is, the null character. Therefore, the first 
 * strlen() returns 0. Since the string literal can be used as a pointer, the second strlen() returns the number of the characters after 
 * the second one. As a result, the program outputs: 0 3.
 * 
*/