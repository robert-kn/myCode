#include <stdio.h>

int main(void)
{
    char * str = "Example";
    int * ptr = (int *) str;

    ptr++;
    printf("%s\n", (char *) ptr+3);
    return 0;
}

/**
 * Answer: Since ptr is declared as a pointer to int, the statement ptr++; makes it point to the fifth character of the string. 
 * In printf(), since the type of ptr is cast to char*, the program displays the part of the string from the eighth character and on. 
 * Since the eighth character is the null character, the program displays nothing.
*/