/* What is the output of the following program? */

#include <stdio.h>
#include <string.h>

void test(char ch, char *ptr);

int main(void)
{
    char str[] = "bacdefghij";

    test(*str-1, &str[5]);
    printf("%s\n", str);
    return 0;
}

void test(char ch, char *ptr)
{
    strcpy(ptr, "12345");
    *ptr = ch;
}

/* Answer: When test() is called, we have ch = *str-1 = str[0]-1 = 'b'-1, so ch becomes
equal to 'a'. We also have ptr = &str[5]. Since ptr points to the sixth element of str,
the statement strcpy(ptr, "12345"); changes its content to "bacde12345". The state-
ment *ptr = ch; is equivalent to str[5] = ch = 'a'. Therefore, the program displays:
bacdea2345 */