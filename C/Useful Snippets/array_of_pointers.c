#include <stdio.h>

#define STR_COUNT 10
const size_t BUF_SIZE = 100;
char buffer[BUF_SIZE];
char *pS[STR_COUNT] = {NULL};
size_t str_size = 0;

int main(void)
{
    for(size_t i = 0 ; i < STR_COUNT ; ++i)
    {
        scanf_s("%s", buffer, BUF_SIZE);
        str_size = strnlen_s(buffer, BUF_SIZE) + 1;
        pS[i] = malloc(str_size);
        if(!pS[i]) return 1;
        strcpy_s(pS[i], str_size, buffer);
    }

    // Release the heap memory
    for(size_t i = 0 ; i < STR_COUNT ; ++i)
    {
        free(pS[i]);
        pS[i] = NULL;
    }
}