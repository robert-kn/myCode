/* A common method that antivirus software uses to identify viruses is signature-based detection. The signature is a sequence of bytes (e.g., F3 BA 20 63 7A 1B) that identify a particular virus. When a 
fle is scanned, the antivirus software searches the fle for signatures that identify the presence of viruses. Write a program that reads a virus signature (e.g., 5 integers) and checks if it is contained in 
the binary fle test.dat. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

int main(void)
{
    FILE *fp;
    int i, found, len, back, buf[SIZE], pat[SIZE];

    fp = fopen("test.dat", "rb");
    if(fp == NULL)
    {
        printf("Error: fopen() failed\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter virus signature (%d integers)\n", SIZE);
    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number: ");
        scanf("%d", &pat[i]);
    }

    len = sizeof(pat);
    found = 0;
    back = len-sizeof(int);

    while(1)
    {
        if(fread(buf, sizeof(int), SIZE, fp) != SIZE)
            break;
        if(memcmp(buf, pat, len) == 0)
        {
            found = 1;
            break;
        }
        else fseek(fp, -back, SEEK_CUR); /* Go back to check the next group of five. */
    }
    if(found == 1)
        printf("SOS: Virus found\n");
    else
        printf("That virus signature isn't found\n" );

    fclose(fp); 
    return 0;
}