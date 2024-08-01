/* Write a function similar to strcpy(). The function should take as parameters two pointers and copy the string pointed to by the second pointer into the memory pointed to by the frst pointer. 
The memory pointed to by the frst pointer should have been allo- cated dynamically and its size should be equal to the length of the copied string. Write a program that reads a string of less 
than 100 characters, calls the function to copy it in the dynamically allocated memory, and displays the content of that memory.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *str_cpy(char *trg, const char *src);
int read_text(char str[], int size, int flag);

int main(void)
{
    char *trg, src[100];
    int len;
    
    printf("Enter text: ");
    len = read_text(src, sizeof(src), 1);

    /* Allocate memory to store the input string and the null character. */

    trg = (char*) malloc(len+1);
    if(trg == NULL)
    {
        printf("Error: Not available memory\n"); 
        exit(EXIT_FAILURE);
    }
    printf("Copied text: %s\n", str_cpy(trg, src));
    free(trg);
    return 0;
}

char *str_cpy(char *trg, const char *src)
{
    int i = 0;
    while(*(src+i) != '\0') /* Or else, while(src[i] != '\0')*/
    {
        *(trg+i) = *(src+i); /* Or else, trg[i] = src[i]; */
        i++;
    }
    *(trg+i) = '\0'; /* Add the null character. */
    return trg;
}

/* We could omit i, we’d get a more complicated code though. Here is an example:
char *str_cpy(char *trg, const char *src)
{
    char *ptr = trg;
    while(*trg++ = *src++)
        ;
    return ptr;
}

The loop executes until the null character is copied into the memory pointed to by trg. For example, in the frst iteration, we have trg[0] = src[0]; and the pointers are increased to 
point to the next elements. In fact, the statement *trg++ = *src++; is equivalent to:

*trg = *src; 
trg++;
src++;
*/