#include <stdio.h>
int main(void)
{
    char ptr[] = "This is text";
    ptr[0] = 'a'; /* this will not cause an error. */
    printf("%s\n", ptr);
    return 0;
}