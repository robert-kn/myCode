/**
 * Write a program that reads a string of less than 100 characters and displays the number of its characters, the number of 'b' 
 * occurrences, and the input string after replacing the space character with the new line character and 'a' with 'p'. Don’t use 
 * the return value of read_text().
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100];
    int i, cnt;

    printf("Enter text: ");
    read_text(str, sizeof(str), 1);

    cnt = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ')
            str[i] = '\n';
        else if(str[i] == 'a')
            str[i] = 'p';
        else if(str[i] == 'b')
            cnt++;
    }
    printf("Len = %d Times = %d\nText = %s\n", i, cnt, str);
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
 * Comments: The loop is executed until the end of the string is met, that is, once str[i] becomes equal to '\0'. After the loop 
 * ends, the value of i specifies the length of the string.
*/