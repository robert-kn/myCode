#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUF_LEN      100                     /* Input buffer size */
#define INIT_STR_EXT  50                     /* Initial space for prose */
#define WORDS_INCR     5                     /* Words capacity increment */

void output();

int main(void)
{
    char delimiters[] = " \n\".,;:!?)(";
    char buf[BUF_LEN];
    size_t str_size = INIT_STR_EXT;
    char* pStr = malloc(str_size);              /* Pointer to prose to be tokenized */
    *pStr = '\0'; 

    printf("Enter some prose with up to %d characters per line.\nTerminate \
    input by entering an empty line:\n", BUF_LEN);

    while(true)
    {
        fgets(buf, BUF_LEN, stdin);

        if(buf[0] == '\n')
            break;
        
        if(strnlen_s(pStr, str_size) + strnlen_s(buf, BUF_LEN) + 1 > str_size)
        {
            str_size = strnlen_s(pStr, str_size) + strnlen_s(buf, BUF_LEN) + 1;
            pStr = realloc(pStr, str_size);
        }

        if(strcat_s(pStr, str_size, buf))
        {
            printf("Something's wrong. String concatenation failed.\n");
            return 1;
        }

        output();
    }

    
    

}

void output()
{
    size_t maxWords = 10;                                               /* Current maximum word count */
    int word_count = 0;                                                 /* Current word count */
    size_t word_length = 0;                                             /* Current word length */
    char** pWords = calloc(maxWords, sizeof(char*));                    /* Stores pointers to the words */
    int* pnWord = calloc(maxWords, sizeof(int));                        /* Stores count for each word */

    size_t str_len = strnlen_s(pStr, str_size);                         /* Length used by strtok_s() */
    char* ptr = NULL;                                                   /* Pointer used by strtok_s() */
    char* pWord = strtok_s(pStr, &str_len, delimiters, &ptr);           /* find 1st word */

    if(!pWord)
    {
        printf("No words found. Ending program.\n");
        return 1;
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
            *(pWords + word_count) = malloc(word_length);
            strcpy_s(*(pWords + word_count), word_length, pWord);
            *(pnWord + word_count++) = 1;
        }
        else
            new_word = true;
    
        pWord = strtok_s(NULL, &str_len, delimiters, &ptr);
    }

    for(int i = 0; i < word_count ; ++i)
    {
        printf("  %-13s  %3d", *(pWords + i), *(pnWord + i));
        if((i + 1) % 4 == 0)
            printf("\n");
    }
    printf("\n");

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