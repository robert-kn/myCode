/***
 * What is the output of the following program?
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "noteasy";

    printf("%s\n", str+(*(str+3)-1)-str[strlen(str+3)]);
    return 0;
}

/***
 * Answer: Since the expression *(str+3) is equivalent to str[3], that is, 'e', the value of *(str+3)-1 is equal to str[3]-1, that is, 
 * 'e'-1 = 'd'. strlen() returns the length of the string after the third character, that is, 4. Therefore, the expression is equivalent 
 * to str+'d'-'a' = str+3 and the program outputs easy.
*/
