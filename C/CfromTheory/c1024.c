/**
 * Does the following program contain an error?
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[] = "abcd", str2[] = {'e', 'f', 'g'};

    strcpy(str1, str2);
    printf("%s\n", str1);
    return 0;
}

/**
 * Answer: Since str2 does not contain the null character, the copy operation won’t perform successfully and a runtime error may occur.
*/