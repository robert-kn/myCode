/* Write a function that takes as parameters a character, an integer, and a string and
uses it as a pointer to check whether the character exists in the string or not. If not, it should
return NULL. Otherwise, if the integer is 0, it should return a pointer to its first occurrence,
otherwise to the last one. Write a program that reads a string of less than 100 characters, a
character, and an integer, calls the function, and displays the part of the string. For exam-
ple, if the user enters "bootstrap", 't' and 0, the program should display tstrap. If it is
"bootstrap", 't' and 3, the program should display trap. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);
char *find(char str[], char ch, int f);

int main(void)
{
    char *ptr, ch, str[100];
    int flag;

    printf("Enter text: ");
    read_text(str, sizeof(str), 1);

    printf("Enter character to search: ");
    scanf("%c", &ch);

    printf("Enter choice (0-first, other-last): ");
    scanf("%d", &flag);

    ptr = find(str, ch, flag);
    if(ptr == NULL)
        printf("'%c' is not included in the text\n", ch);
    else
        printf("The rest string is: %s\n", ptr);
    return 0;
}


char *find(char str[], char ch, int f)
{
    char *tmp = NULL; /* Initial value in case the character is not found. */

    while(*str != '\0')
    {
        if(*str == ch)
        {
            tmp = str;
            if(f == 0) /* If the character is found and the choice is 0, the loop terminates and the function returns the pointer. Otherwise, tmp points to the place of the last occurrence. */
                break;
        }
        str++;
    }
    return tmp;
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