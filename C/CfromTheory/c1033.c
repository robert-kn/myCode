/**
 * Write a program that reads a string of less than 100 characters and displays the words that it consists of and their number. Suppose 
 * that a word is a sequence of character(s) that does not contain space character(s).For example,if the user enters how many words ?
 * (notice that more than one space may be included between the words), the program should display.
 * 
 * 
 * how
 * many
 * words
 * ?
 * The text contains 4 words
 * 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100];
    int i, words;

    i = words = 0;

    printf("Enter text: ");
    read_text(str, sizeof(str), 1);

    if(str[0] != ' ' && str[0] != '\t' && str[0] != '\0') /* If the first character is other than the space character, it means that a word begins, so the value of words is incremented. */
        words++;

    while(str[i] != '\0')
    {
        if(str[i] == ' ' || str[i] == '\t')
        {
            /* Since more than one space character may be included between words, we check if the next character, that is str[i+1], is also a space character. If it isn't, it means that a new word begins, so the value of words is increased. */
        
            if(str[i+1] != ' ' && str[i+1] != '\t' && str[i+1] != '\0')
            {
                words++;
                printf("\n");
            }
        }
        else
            printf("%c", str[i]);
        i++;
    }
    printf("\nThe text contains %d words\n", words); 
    return 0;
}
