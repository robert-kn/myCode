/**
 * What is the output of the following program?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char *ptr[3], str[100];
    int i;

    for(i = 0; i < 3; i++)
    {
        printf("Enter text: ");
        read_text(str, sizeof(str), 1);
        ptr[i] = str;
    }

    for(i = 0; i < 3; i++)
        printf("%c\n", *ptr[i]);
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
 * 
 * Answer: The ptr variable is declared as an array of three pointers to character. In each iteration, the statement ptr[i] = str; 
 * makes all pointers up to i point to the first character of the string stored in str array. Since all pointers point to the same 
 * address, the second loop displays three times the first character of the last input string.
*/