#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void sorting(bool sorted, int str_count, char **pS, char * pTemp);

#define BUF_LEN 100
#define COUNT    5



int main(void)
{
    char buf[BUF_LEN];
    size_t str_count = 0;
    size_t capacity = COUNT;
    char **pS = calloc(capacity, sizeof(char*));
    char** psTemp = NULL;
    char* pTemp = NULL;
    size_t str_len = 0;
    bool sorted = false;

    printf("Enter strings to be sorted, one per line. Press Enter to end:\n");
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
            capacity += COUNT;

            if(!(psTemp = realloc(pS, capacity))) return 1;

            pS = psTemp;
        }
        str_len = strnlen(buf, BUF_LEN) + 1;
        if(!(pS[str_count] = malloc(str_len))) 
            return 2;
        strcpy(pS[str_count++], buf);
    }
    
    sorting(!sorted, str_count, pS, pTemp);

    free(pS);
    pS = NULL;
    return 0;
}

void sorting(bool sorted, int str_count, char ** pS, char * pTemp)
{
    sorted = true;
    for(size_t i = 0 ; i < str_count - 1 ; ++i)
    {
        if(strcmp(pS[i], pS[i + 1]) > 0)
        {
            sorted = false;
            pTemp = pS[i];
            pS[i] = pS[i + 1];
            pS[i + 1] = pTemp;
        }
    }
    printf("Your input sorted in ascending sequence is:\n\n");
    for(size_t i = 0 ; i < str_count ; ++i)
    {
        printf("%s", pS[i]);
        free(pS[i]);
        pS[i] = NULL;
    }
}