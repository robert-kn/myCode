
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main (void)
{
    char delimiters[] = " \".,;:!?)()";             /* Prose delimiters */
    char buf[100];                                  /* Buffer for a line of keyboard input */
    char str[1000];                                 /* Stores the prose to be tokenized*/
    char * ptr = NULL;                              /* Pointer used by strtok_s() */
    str[0] = "\0";                                  /* necessary to allow the first input string to be concatenated to str. */

    size_t str_len = sizeof(str);
    size_t buf_len = sizeof(buf);
    printf("Enter some prose that is less than %u characters .\n Terminate input by entering an empty line:\n", str_len);

    /* Read multiple lines of prose from the keyboard */ 
    while(true)
    {
        if(!gets_s(buf, buf_len))        /* read a line of input */
        {
            printf("Error reading string.\n");
            return 1;
        }
        if(!strlen_s(buf, buf_len))     /* an empty line ends input*/
            break;

        if(strcat_s(str, str_len, buf))
        {
            printf("Maximum permitted input length exceeded.\n");
            return 1;
        }
    }
    printf("The words in the prose that you entered are:\n", str);

    /* Find and list all the words in the prose */
    unsigned int word_count = 0;
    char * pWord = strtok_s(str, &str_len, delimiters, &ptr);           /* Find 1st word */

    if(pWord)
    {
        do
        {
            printf("%-18s", pWord);
            if(++word_count % 5 == 0)
                printf("\n");
            pWord = strtok_s(NULL, &str_len, delimiters, &ptr);        /* Find subsequent words */
        } while(pWord);                                                /* NULL ends tokenizing */
        printf("\n%u words found.\n", word_count);
    }
    else
        printf("No words found.\n");
    
    return 0;
}

/* problem with this program is that gets doesn't store the newline character hence if no space is added at either the end of a line or 
beginning of the next, the last word in previous line will be concatenated with the first word in the next as though they were a single word */