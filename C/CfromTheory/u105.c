/* What is the output of the following program? nothing */

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "test", *p = str;
    *str = str[strlen(str)];
    while(*p)
        printf("%s", p++);
    return 0;
}