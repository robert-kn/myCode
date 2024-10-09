/* Write a program that reads the name of a fle and displays its second line. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    FILE *fp;
    char str[100];
    int ch, lines;
    
    printf("Enter file name: "); 
    read_text(str, sizeof(str), 1);

    fp = fopen(str, "r");

    if(fp == NULL)
    {
        printf("Error: fopen() failed\n");
        exit(EXIT_FAILURE);
    }

    printf("\nLine contents\n");
    lines = 1;

    while(1)
    {
        ch = getc(fp); 
        if((ch == EOF) || (lines > 2))
            break;
        if(ch == '\n') /* Once the new line character is read, increment the variable that counts the lines. */
            lines++;
        if(lines == 2) /* Only the characters of the second line are displayed. */
            printf("%c", ch);
    }
    fclose(fp);
    return 0;
}

/* Once the program displays the second line, the loop terminates. */

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