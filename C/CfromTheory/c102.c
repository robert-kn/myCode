/**
 * Write a program that creates a string with all lowercase and uppercase letters of the 
 * English alphabet.
*/

#include <stdio.h>

int main(void)
{
    char str[53];
    int i;

    for(i = 0; i < 26; i++)
    {
        str[i] = 'a'+i;
        str[26+i] = 'A'+i;
    }

    str[52] = '\0'; /* At the end, we add the null character. */
    /* printf("%s\n", str); */
    puts(str);
    return 0;
}

/** Comments: In each iteration, the ASCII value of the respective character is stored in str.
For example, in the first iteration (i=0), we have str[0] = 'a'+0 = 'a' = 97 and str[26] =
'A'+0 = 'A' = 65. */