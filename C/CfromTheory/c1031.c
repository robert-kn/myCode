/**
 * What is the output of the following program?
*/

#include <stdio.h> 
#include <string.h>

int main(void)
{
    char str1[10], str2[] = "engine";

    printf("%c\n", ++str1[strcmp(strcpy(str1, "ine"), str2+3)+2]);

}

/**
 * Answer: strcpy() copies the string "ine" into str1 and returns a pointer to str1. strcmp() compares the string pointed to by the 
 * return value of strcpy(), that is, str1, with the part of the string stored in the str2+3 position, that is, "ine". Since both strings 
 * are the same, strcmp() returns 0 and the program displays the value of ++str1[0+2]. Since str1[2] is 'e', the program outputs f.
 * 
*/