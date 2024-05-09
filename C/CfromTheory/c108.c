/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void)
{
    char * str = "this";

    for(; *str; printf("%s ", str++));

    return 0;
}

/**
 * Answer: The expression *str is equivalent to *str != 0. Therefore, the loop is executed until the null character is met. In the 
 * first iteration, str points to the first character of the string. Therefore, printf() displays this and str is advanced to point 
 * to the next character. The next call of printf() displays his, and so on. Therefore, the program outputs: this his is s
*/