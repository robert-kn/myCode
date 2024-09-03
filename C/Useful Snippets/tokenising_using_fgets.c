
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (void)
{
    char delimiters[] = " \".,;:!?)()";             
    char buf[100];                                  
    char str[1000];                                 
    char * ptr = NULL;                              
    str[0] = '\0';                                  

    size_t str_len = sizeof(str);
    size_t buf_len = sizeof(buf);
    printf("Enter some prose that is less than %lu characters .\n Terminate input by entering an empty line:\n", str_len);

    /* Read multiple lines of prose from the keyboard */ 
    while(true)
    {
        if(fgets(buf, buf_len, stdin))         /* read a line of input */
        {
            printf("Error reading string.\n");
            return 1;
        }
        if(buf[0] == '\n')                      /* an empty line ends input*/
            break;

        if(!strcat(str, buf))
        {
            printf("Maximum permitted input length exceeded.\n");
            return 1;
        }
    }
    printf("\nThe words in the prose that you entered are:\n\n%s", str);

    /* Find and list all the words in the prose */
    unsigned int word_count = 0;
    char * pWord = strtok_r(str, delimiters, &ptr);           /* Find 1st word */

    if(pWord)
    {
        do
        {
            printf("%-18s", pWord);
            if(++word_count % 5 == 0)
                printf("\n");
            pWord = strtok_r(NULL, delimiters, &ptr);        /* Find subsequent words */
        } while(pWord);                                                /* NULL ends tokenizing */
        printf("\n%u words found.\n", word_count);
    }
    else
        printf("No words found.\n");
    
    return 0;
}