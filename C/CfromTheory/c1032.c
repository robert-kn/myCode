/**
 * The data compression algorithm run length encoding (RLE) is based on the assumption that a symbol within the data stream may be 
 * repeated many times in a row. This repetitive sequence can be replaced by an integer that declares the number of the repetitions 
 * and the symbol itself. Write a program that reads a string of less than 100 characters and uses the RLE algorithm to compress it. 
 * Don’t compress digits and characters that appear once. For example, the string: fffmmmm1234jjjjjjjjjjx should be compressed to 
 * 3f4m123410jx
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100];
    int i, len, cnt;

    printf("Original text: ");
    len = read_text(str, sizeof(str), 1);

    printf("Compressed text: "); 
    i = 0;

    while(i < len)
    {
        cnt = 1;
        if(str[i] < '0' || str[i] > '9')   /* Digit are not compressed. */
        {
            while(str[i+cnt] == str[i]) /* check if thew current character, that is str[i], is repeated in the next places */
                cnt++;
            
            if(cnt == 1)
                printf("%c", str[i]);
            else
                printf("%d%c", cnt, str[i]);
        }
        else
            printf("%c", str[i]);
        
        i += cnt;
    }
    return 0;
}

int read_text(char str[], int size, int flag) 
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(str);

    if(len > 0)
    {
        if(flag && (str[len-1] == '\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}