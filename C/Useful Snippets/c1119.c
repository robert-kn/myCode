/* Does the following program contain any error? If not, what does it output? */

#include <stdio.h>
#include <string.h>

char * test(void);

int main(void)
{
    char ptr[100] = "sample";

    strcpy(ptr, test());
    printf("%s\n", ptr);
    return 0;
}

char * test(void)
{
    char str[] = "example";
    return str;
}

/* Answer: You’ve been warned that you’ll encounter such an exercise. Let’s see, did you find
the error or you answered that it is correct?
When test() is called, the compiler allocates memory for the str array and stores the
string into it. This memory location is returned. Remember that the memory of a local vari-
able is released when the function terminates. Most probably, the program won’t display
example. But even if it is displayed, the code is erroneous.
Always remember, don’t return the address of a local variable unless it is declared as static.
If you want to change the contents of an array, the simplest way is to pass the array as an
argument. For example, test() is modified like this:

void test(char str[])
{
    strcpy(str, "example");
}
*/