/* Because a C program executes rather quickly, the C language is often used for implementing cipher 
algorithms. As an example, we’ll describe one of the most simple and famous cipher algorithms.

The Caesar algorithm is one of the oldest cipher methods used by Julius Caesar to encrypt his messages. 
According to this algorithm, each character is substituted by the one located in the next three places. 
For example, if we apply the Caesar algorithm in the English alphabet, the message "Watch out for Ovelix !!!" 
is encrypted as "Zdwfk rxw iru Ryhola !!!". Notice that the character 'x' is encrypted as 'a' because the 
sub- stitution continues from the beginning of the alphabet. Similarly, 'y' is replaced by 'b' and 'z' by 
'c'. The recipient decrypts the message by substituting each character with the one located three places 
before it.

Write a program that provides a menu to perform the following operations:

1. File Encryption. The program should read the name of a fle and the key that will be used to encrypt 
its content. For example, in the case of Caesar algorithm, the key is 3. The program should encrypt only 
the lowercase and uppercase characters.
2. File Decryption. The program should read the name of a fle and the key that will be used to decrypt its 
content.
3. Program Termination.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cipher(FILE *fp_in, FILE *fp_out, int key); 
void decipher(FILE *fp_in, FILE *fp_out, int key); 
int read_text(char str[], int size, int flag);

int main(void)
{
    FILE *fp_in, *fp_out;
    char str[100];
    int sel, key;

    while(1)
    {
        printf("\nMenu selections\n"); 
        printf("---------------\n"); 
        printf("1. Cipher\n");
        printf("2. Decipher\n"); 
        printf("3. Exit\n");

        printf("\nEnter choice: "); 
        scanf("%d", &sel);

        switch(sel)
        {
            case 1:
            case 2:
                /* Check whether the input key is valid or not. Since we are using the English alphabet, the valid values are between 1 and 25. */
                do
                {
                    printf("Enter key size: ");
                    scanf("%d", &key);
                } while (key < 1 || key > 25);

                getchar();
                printf("Input file: ");
                read_text(str, sizeof(str), 1);
                fp_in = fopen(str, "r");
                if(fp_in == NULL)
                {
                    printf("Error: fopen() for %s failed\n", str);
                    exit(EXIT_FAILURE);
                }
                printf("Output file: ");
                read_text(str, sizeof(str), 1);
                fp_out = fopen(str, "w"); 
                if(fp_out == NULL)
                {
                    printf("Error: fopen() for %s failed\n", str);
                    exit(EXIT_FAILURE);
                }
                if(sel == 1) 
                    cipher(fp_in, fp_out, key);
                else
                    decipher(fp_in, fp_out, key);
                fclose(fp_in);
                fclose(fp_out);
            break;

            case 3:
            return 0;

            default:
                printf("\nWrong choice\n"); 
            break;
        }
    }
    return 0;
}


void cipher(FILE *fp_in, FILE *fp_out, int key)
{
    int ch;
    while(1)
    {
        ch = getc(fp_in); 
        if(ch == EOF)
            return;
        /* Only the lower and upper case characters are encrypted. */
        if(ch >= 'A' && ch <= 'Z')
        {
            ch += key;
            if(ch > 'Z')
                ch -= 26;
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            ch += key; 
            if(ch > 'z')
                ch -= 26;
        }
        putc(ch, fp_out);
    }
}

void decipher(FILE *fp_in, FILE *fp_out, int key)
{
    int ch;
    while(1)
    {
        ch = getc(fp_in); 
        if(ch == EOF)
            return;
        /* Only the lower and upper case characters are decrypted. */
        if(ch >= 'A' && ch <= 'Z')
        {
            ch -= key;
            if(ch < 'A') 
                ch += 26;
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            ch -= key;
            if(ch < 'a') 
                ch += 26;
        }
        putc(ch, fp_out);
    }
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

/* In cipher(), the key is added to each character. If the new value exceeds the last character of the 
alphabet ('Z' or 'z'), we subtract 26 to go back to the beginning of the alphabet. In decipher(), the 
reverse actions take place. */