/* This program generates a segmentation fault when run */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sorting(int str_count, char ** pS);

#define BUF_LEN 100
#define COUNT    5



int main(void)
{
    char buf[BUF_LEN];
    size_t str_count = 0;
    size_t capacity = COUNT;
    char ** pS = calloc(capacity, sizeof(char*));
    char ** psTemp = NULL;
    size_t str_len = 0;

    printf("Enter strings to be sorted, one per line. Press Enter to end:\n\n");
    char *ptr = NULL;

    while(true)
    {
        ptr = fgets(buf, BUF_LEN, stdin);
        if(!ptr)
        {
            printf("Error reading string.\n");
            free(pS);
            pS = NULL;
            return 1;
        }

        if(*ptr == '\n') 
        {
            printf("No input, ending program.\n");
            break;
        }
            

        if(str_count == capacity)
        {
            capacity += capacity/4;

            if(!(psTemp = (char **) realloc(pS, capacity))) 
                return 2;

            pS = psTemp;
        }
        str_len = strnlen(buf, BUF_LEN) + 1;
        if(!(pS[str_count] = (char *) malloc(str_len))) 
            return 3;
        strlcpy(pS[str_count++], buf, str_len);
    }

    if(str_count > 0)
        sorting(str_count, pS);

    free(pS);
    pS = NULL;
    return 0;
}

void sorting(int str_count, char ** pS)
{
    char * pTemp = NULL;
    size_t i;

    for(i = 0 ; i < str_count - 1 ; i++)
    {
        if(strcmp(pS[i], pS[i + 1]) > 0)
        {
            pTemp = pS[i];
            pS[i] = pS[i + 1];
            pS[i + 1] = pTemp;
        }
    }
    printf("\nYour input sorted in ascending sequence is:\n\n");
    for(i = 0 ; i < str_count ; i++)
    {
        printf("%s\n", pS[i]);
        free(pS[i]);
        pS[i] = NULL;
    }
}