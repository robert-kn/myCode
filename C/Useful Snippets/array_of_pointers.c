#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_COUNT 10


int main(void)
{
    const size_t BUF_SIZE = 100;
    char buffer[BUF_SIZE];
    char *pS[STR_COUNT] = {NULL};
    size_t str_size = 0;

    for(size_t i = 0 ; i < STR_COUNT ; ++i)
    {
        fgets(buffer, BUF_SIZE, stdin);
        str_size = strnlen(buffer, BUF_SIZE) + 1;
        pS[i] = malloc(str_size);
        if(!pS[i]) 
            return 1;
        strlcpy(pS[i], buffer, str_size);
    }

    printf("\nHere are the strings you entered\n\n");
    for(size_t i = 0 ; i < STR_COUNT ; ++i)
    {
        printf("%s\n", *(pS + i));
        free(pS[i]);
        pS[i] = NULL;
    }
    return 0;
}