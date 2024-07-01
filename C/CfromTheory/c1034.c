/**
 * A simple algorithm to encrypt data is the algorithm of the single transformation.
Let’s see how it works. In one line, we write the letters of the used alphabet. In a second
line, we write the same letters in a different order. This second line constitutes the cryp-
tography key. For example, see Figure 10.2.

Each letter of the original text is substituted with the respective key letter. For example,
the word test is encrypted as binb.

Write a program that reads a string of less than 100 characters, the key string consisting
of 26 characters, and encrypts the lowercase letters of the input string. Then, the program
should decrypt the encrypted string and display it (should be the same with the original
string). The program should check that the key characters are 26 and appear only once.
 */

/* Single transformation algorithm. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LETTERS 26

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100], key[LETTERS+1];
    int i, j, len, error;

    printf("Enter text: ");
    len = read_text(str, sizeof(str), 1);

    do
    {
        error = 0;
        printf("Enter key (%d different characters): ", LETTERS);
        read_text(key, sizeof(key), 1);

        if(strlen(key) != LETTERS)
        {
            printf("Error: Key must be of %d characters\n", LETTERS);
            error = 1;
        }
        else
        {
            for(i = 0; i < LETTERS; i++)
            {
                for(j=i+1; j < LETTERS; j++)
                {
                    if(key[i] == key[j])
                    {
                        error = 1;
                        printf("Key characters must be different\n");
                        getchar();
                        break;
                    }
                }
                if(error == 1)
                    break;
            }
        }
    }while(error != 0);

    for(i = 0; i < len; i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
            str[i] = key[str[i]-'a'];
    }
    printf("Encrypted text: %s\n", str);
    for(i = 0; i < len; i++)
    {
        for(j = 0; j < LETTERS; j++)
        {
            if(str[i] == key[j])
            {
                str[i] = 'a'+j;
                break;
            }
        }
    }
    !printf("Original text: %s\n", str);
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