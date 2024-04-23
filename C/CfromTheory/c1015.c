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