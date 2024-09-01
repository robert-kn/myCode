/**
 * Finds the number of occurrences of each unique word in some arbitrary prose. this version allocates memory on the
 * heap to store the prose, the words, and the word counts. 
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_LEN      100                     
#define INIT_STR_SPACE  50                     
#define WORDS_INCR     5          


int output(char * pStr, size_t str_size, char delimiters[]);
void print_words(int word_count, char ** pWords, int * pnWord);

int main(void)
{
    char delimiters[] = " \n\".,;:!?)(";
    char buf[BUF_LEN];
    size_t str_size = INIT_STR_SPACE;
    char * pStr = malloc(str_size);              /* Pointer to prose to be tokenized */
    *pStr = '\0'; 

    printf("Enter some prose with up to %d characters per line.\nTerminate input by entering an empty line:\n\n", BUF_LEN);

    while(true)
    {
        fgets(buf, BUF_LEN, stdin);

        if(buf[0] == '\n')
            break;
        
        if(strnlen(pStr, str_size) + strnlen(buf, BUF_LEN) + 1 > str_size)
        {
            str_size = strnlen(pStr, str_size) + strnlen(buf, BUF_LEN) + 1;
            pStr = realloc(pStr, str_size);
        }

        if(strlcat(pStr, buf, str_size) >= (strlen(pStr) + strlen(buf)))
        {
            printf("Something's wrong. String concatenation failed.\n");
            free(pStr);
            return 1;
        }
    }

    output(pStr, str_size, delimiters);
}

int output(char * pStr, size_t str_size, char delimiters[])
{
    size_t maxWords = 10;   
    int word_count = 0;                                                                                             
    size_t word_length = 0;                                             
    char ** pWords = calloc(maxWords, sizeof(char*));                    
    int * pnWord = calloc(maxWords, sizeof(int));                        

    size_t str_len = strnlen(pStr, str_size);                         
    char * ptr = NULL;                                                   
    char * pWord = strtok_r(pStr, delimiters, &ptr);           

    if(!pWord)
    {
        printf("No words found. Ending program.\n");
        return 2;
    }

    bool new_word = true;

    while(pWord)
    {
        for(int i = 0 ; i < word_count ; ++i)
        {
            if(strcmp(*(pWords + i), pWord) == 0)
            {
                ++*(pnWord + i);
                new_word = false;
                break;
            }
        }
    

        if(new_word) 
        {
            if(word_count == maxWords)
            {
                maxWords += WORDS_INCR;
                pWords = realloc(pWords, maxWords*sizeof(char*));

                pnWord = realloc(pnWord, maxWords*sizeof(int));
            }
            word_length = ptr - pWord; 
            *(pWords + word_count) = malloc(word_length);   /* pWords[word_count] = malloc(word_length)*/
            strlcpy(*(pWords + word_count), pWord, word_length);
            *(pnWord + word_count++) = 1;
        }
        else
            new_word = true;
    
        pWord = strtok_r(NULL, delimiters, &ptr);
    }

    print_words(word_count, pWords, pnWord);

    

    for(int i = 0; i < word_count ; ++i)
    {
        free(*(pWords + i));
        *(pWords + i) = NULL;
    }

    free(pWords);
    pWords = NULL;                                             
    free(pnWord);  
    pnWord = NULL;                                           
    free(pStr);     
    pStr = NULL;                                          
    return 0;
}

void print_words(int word_count, char ** pWords, int * pnWord)
{
    for(int i = 0; i < word_count ; ++i)
    {
        printf("  %-13s  %3d", *(pWords + i), *(pnWord + i));
        if((i + 1) % 4 == 0)
            printf("\n");
    }
    printf("\n");

}