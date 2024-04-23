/***
 * Write a program that reads a string of less than 100 characters and displays it after replacing all 'a' characters that may appear 
 * at the beginning and at the end of the string with the space character. For example, if the user enters "aabcdaa", the program should 
 * display " bcd ", while if the input string is "bcdaa", the program should display "bcd ".
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100];
    int i, len;

    printf("Enter text: ");
    len = read_text(str, sizeof(str), 1);

    for(i = 0; i < len; i++)
    {
        if(str[i] == 'a')
            str[i] = ' ';
        else
            break;
    }

    for(i = len-1; i >= 0; i--)
    {
        if(str[i] == 'a')
            str[i] = ' ';
        else
            break;
    }
    printf("Text: %s\n", str);
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
 * Comments: The first loop compares the characters in the beginning of the string with 'a'. If it is an 'a', it is replaced with the 
 * space character; otherwise, the loop is terminated. Similarly, the second loop replaces all 'a' characters at the end of the string 
 * with the space character.
*/