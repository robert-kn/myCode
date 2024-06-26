/**
 * Write a program that reads a string of less than 100 characters and displays a message to indicate if it is a palindrome, which means 
 * if it can be read the same in either direction. For example, the string level is a palindrome, since it is read the same in both 
 * directions.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100];
    int i, diff, len;

    printf("Enter text: ");
    len = read_text(str, sizeof(str), 1);

    diff = 0;
    for(i = 0; i < len/2; i++)
    {
        if(str[i] != str[len-1-i]) /* If two characters are not the same, the loop terminates */
        {
            diff = 1;
            break;
        }
    }

    if(diff == 1)
        printf("%s is not a palindrome\n", str);
    else
        printf("%s is a palindrome\n", str);
    return 0;
}

int read_text(char str[], int size, int flag) 
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(str);

    if(len > 0)
    {
        if(flag && (str[len-1] == '\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}

/**
 * Comments: The loop compares the characters from the first character up to the middle one with the characters from the last one 
 * back to the middle. That’s why the loop is executed from 0 up to len/2. The last character is stored in str[len-1].
*/