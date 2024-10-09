#include <stdio.h>
int main(void)
{
    char * ptr = "This is text";
    ptr[0] = 'a'; /* this will cause an error because the memory that the compiler allocates to store a string literal is typically read-only. */
    return 0;
}