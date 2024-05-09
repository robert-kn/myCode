/**
 * What is the output of the following program?
*/

#include <stdio.h> 
#include <string.h> 

int main(void)
{
    char str[5];

    str[0] = 't';
    str[1] = 'e';
    str[2] = 's';
    str[3] = 't';

    if(strcmp(str, "test") == 0)
        printf("One\n");
    else
        printf("Two\n");
    return 0; 
}

/**
 * Answer: Did you answer One but Two is displayed? Bad luck, next time ...
 * 
 * The str array contains the 't', 'e', 's', and 't' characters, but str[4] is unassigned. On the other hand, the string literal "test" 
 * ends with the null character. If the random value of str[4] is not 0 the two contents are different, so strcmp() returns a nonzero 
 * value and the program displays Two.
 * 
 * To continue... If we write char str[5] = {'t', 'e', 's', 't'}; what will be the out- put? One or Two?
 * 
 * Since the noninitialized elements are set to 0, str[4] becomes '\0' and the program displays One. What about if we change the 
 * condition to:
 * 
 * if(strcmp(str, "test\0") == 0)
 * 
 * No difference, the program displays One.
*/