#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    const size_t BUF_SIZE = 100;                     
    char buffer[BUF_SIZE];                           
    fgets(buffer, BUF_SIZE, stdin); 

    size_t length = strnlen(buffer, BUF_SIZE) + 1;
    char *pString = malloc(length);
    if(!pString)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    strlcpy(pString, buffer, length);                
    printf("%s", pString);
    free(pString); 
    pString = NULL;
    return 0;
}
