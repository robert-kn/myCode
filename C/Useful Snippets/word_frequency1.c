/**
 * You are going to develop a program that will read a paragraph of text of an arbitrary length that is entered 
 * from the keyboard and determine the frequency of which each word in the text occurs, ignoring case. The 
 * paragraph length won’t be completely arbitrary, as you’ll have to specify some limit for the array size within 
 * the program, but you can make the array that holds the text as large as you want.
 */

#define __STDC_WANT_LIB_EXT1__ 1            /* Make optional versions of functions available */  
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TEXT_LEN  10000                     /* Maximum length of text */ 
#define BUF_SIZE 100                        /* Input buffer size */ 
#define MAX_WORDS   500                     /* Maximum number of different words */
#define WORD_LEN    12                     /* Maximum word length */ 

void extract(char text[], char words[][], char delimiters[], int word_count, int nword[]);
void output(char words[][], int word_count, int nword[]);

int main(void)
{
    char delimiters[] = " \n\".,;:!?)(";       
    char text[TEXT_LEN] = "";               /* Stores the complete text */
    char buf[BUF_SIZE];                     /* Stores one input line */
    char words[MAX_WORDS][WORD_LEN];        /* Stores words from the text */
    int nword[MAX_WORDS] = {0};             /* Number of word occurrences */
    int word_count = 0;                     /* Number of words stored */

    printf("Enter text on an arbitrary number of lines.");
    printf("\nEnter an empty line to end input:\n");

    /* Read an arbitrary number of lines of text */
    while(true)
    {
        /* An empty string containing just a newline signals end of input */
        fgets(buf, BUF_SIZE, stdin);
        
        if(buf[0] == '\n')
            break;

        /* Check if we have space for latest input */
        if(strcat_s(text, TEXT_LEN, buf))
        {
            printf("Maximum capacity for text exceeded. Terminating program.\n");         
            return 1;
        }
    }

    /* extract words from text array and store them in the words array */
    extract(text, words, delimiters, word_count, nword);

    /* output the words and their frequencies of occurrence. */
    output(words, word_count, nword);
    return 0;
}



void extract(char text[], char words[][WORD_LEN], char delimiters[], int word_count, int nword[])
{
    size_t len = TEXT_LEN;
    char *ptr = NULL;
    char* pWord = strtok_s(text, &len, delimiters, &ptr); /* Find 1st word and return its address */

    if(!pWord)
    {
        printf("No words found. Ending program.\n");
        return 1;
    }

    strcpy_s(words[word_count], WORD_LEN, pWord);       /* copy the word into the words array. Thus words[0] will contain the first word */
    ++nword[word_count];                              /* increment the value in the nword arr element from 0 to 1 */
    word_count++;                                      /* and increment word_count to 1. */

    bool new_word = true;

    while(true)                                                 /* False for an existing word */
    {
        pWord = strtok_s(NULL, &len, delimiters, &ptr);         /* Find subsequent word. The NULL argument indicates that the call is to find words in the string previously passed to the function*/

        if(!pWord)
            break;

        /* Check for existing word */
        for(int i = 0; i < word_count; ++i)
        {
            if(strcmp(words[i], pWord) == 0)
            {
                ++nword[i];
                new_word = false;
            }
        }

        if(new_word)
        {
            strcpy_s(words[word_count], WORD_LEN, pWord);
            ++nword[word_count++];
        }
        else
            new_word = true;                    /* Reset new word flag */

        if(word_count > MAX_WORDS - 1)
        {
            printf("Capacity to store words exceeded.\n");
            return 1;
        }
        
    }
}


void output(char words[][WORD_LEN], int word_count, int nword[])
{
    for(int i = 0; i < word_count ; ++i)
    {
        printf("  %-13s  %3d", words[i], nword[i]);
        if((i + 1) % 4 == 0)
            printf("\n");
    }
    printf("\n");
}
