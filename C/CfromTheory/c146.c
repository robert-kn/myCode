/* Write a function that takes as parameters three pointers to strings and stores the last two strings into the frst one. The memory for the frst string should have been allocated 
dynamically. Write a program that reads two strings of less than 100 characters and uses the function to store them into a dynamically allocated memory. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_cat(char *fin, char *str1, char *str2); 
int read_text(char str[], int size, int flag);

int main(void)
{
    char *fin, str1[100], str2[100];
    int len1, len2;
    printf("Enter first text: "); 
    len1 = read_text(str1, sizeof(str1), 1);

    printf("Enter second text: ");
    len2 = read_text(str2, sizeof(str2), 1);
    /* Allocate memory to store both strings and the null character. */

    fin = (char*) malloc(len1+len2+1);
    if(fin == NULL)
    {
        printf("Error: Not available memory\n"); 
        exit(EXIT_FAILURE);
    }

    str_cat(fin, str1, str2); 
    printf("Merged text: %s\n", fin); 
    free(fin);
    return 0;
}

void str_cat(char *fin, char *str1, char *str2)
{
    while(*str1 != '\0') /* Or else, while(*str1) */
        *fin++ = *str1++;

    /* Copy the second string after the first one. */
    while(*str2 != '\0') /* Or else, while(*str2) */
        *fin++ = *str2++;
    *fin = '\0'; /* Add the null character. */
}

/* The frst loop copies the characters of the string pointed to by str1 into the memory pointed to by fin. Similarly, the next loop adds the characters of the second string. Instead of while loops, we 
could use for loops, as follows:

void str_cat(char *fin, char *str1, char *str2)
{
    for(; *str1; *fin++ = *str1++);
    for(; *str2; *fin++ = *str2++);
    *fin = '\0';
}

Notice the ; at the end of both for statements. How about a more complex solution with a single loop?

void str_cat(char *fin, char *str1, char *str2)
{
    for(; *str2; *str1 ? *fin++ = *str1++ : *fin++ = *str2++);
    *fin = '\0';
}

That’s another example of what we consider bad coding style. Don’t forget our advice. Write code having simplicity in mind.
*/