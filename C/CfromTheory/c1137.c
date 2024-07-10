/* Write a function that takes as parameter a string and displays how many digits (0-9) it
contains, how many words begin with a lowercase letter (a-z), and how many with an upper-
case (A-Z). Write a program that reads a string of less than 100 characters and calls the function.
There are two restrictions. The first one is to use pointer notation inside the function,
and the second is to use functions from ctype.h. Read the descriptions of ctype.h func-
tions in Appendix C and select the proper ones. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int read_text(char str[], int size, int flag);
void parse_str(char str[]);


int main(void)
{
    char str[100];
    printf("Enter text: ");
    read_text(str, sizeof(str), 1);
    parse_str(str);
    return 0;
}

void parse_str(char s[])
{
    int dig, uplet_wrd, lowlet_wrd;

    dig = uplet_wrd = lowlet_wrd = 0;

    while(*s != '\0')
    {
        while(isspace(*s)) /* Skip the whitespace characters until a word begins. */
            s++;

        if(*s == '\n')
            break;  

        /* We check if the word begins with a digit or letter.*/
        if(isdigit(*s))
            dig++;

        else if(isupper(*s))
            uplet_wrd++;

        else if(islower(*s))
            lowlet_wrd++;

        s++; 

        if(*s == '\0')
            break;

        while(isspace(*s) == 0)  /* Skip the characters of the word; check only for digits. */   
        {
            if(isdigit(*s))
                dig++;
            s++;
            if(*s == '\0')
                break;
        }
    
    }
    printf("UL:%d LL:%d DG:%d\n", uplet_wrd, lowlet_wrd, dig);

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