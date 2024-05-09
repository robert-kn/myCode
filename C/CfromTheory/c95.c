/**
 * Write a program that displays all lowercase letters in one line, all uppercase letters in a second line, and all characters that represent the digits 0-9 in a third line. Use a single for loop.
*/

#include <stdio.h>

int main(void)
{
    char ch, end_ch;

    end_ch = 'z';

    for(ch = 'a'; ch <= end_ch; ch++)
    {
        printf("%c ", ch);
        if(ch == 'z')
        {
            ch = 'A'-1;       /* Subtract 1, so that the ch++ statement in the next iteration makes it 'A'. */
            end_ch = 'Z';    /* Change the end character, so that the loop displays the uppercase letters. */  
        }
        else if(ch == 'Z')
        {
            ch = '0'-1;
            end_ch = '9';
            printf("\n");
        }
    }
    return 0;
}

/**
 * Comments: How about writing the loop without using the end_ch variable and any of the if-else-if statements? Here you are.
*/

/**
 * for(ch = 'a'; ch != '9'+1; ch++)
{
    printf("%c ", ch);
    ch = (ch == 'z') ? 'A' - 1: (ch == 'Z') ? '0' - 1: ch;
    (ch == 'A' - 1 || ch == '0'-1) ? printf("\n"): 1;
} 
*/

/***
 * Quite simple, isn’t it? We don’t think you need any explanation ...
 * Just kidding, we wanted to show you an incomprehensible version of the same code. Don’t forget our advice: write clear code for your own benefit and for the benefit of those who are going to read your code.
*/