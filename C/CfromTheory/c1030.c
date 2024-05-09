/**
 * Write a program that continuously reads strings (less than 100 characters each) and displays the “shortest” and “longest” strings. If 
 * the input string begins with end, the insertion of strings should terminate; end does not participate in the comparison.
 * 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

int read_text(char str[], int size, int flag);

int main(void)
{
    char str[100], min_str[100], max_str[100];

    printf("Enter text: ");
    read_text(str, sizeof(str), 1);

    /* Store the first string as shortest and longest as a first reference to make the comparisons. */

    strcpy(min_str, str); 
    strcpy(max_str, str);

    if(strncmp(str, "end", 3) == 0)
    {
        printf("\nMax = %s Min = %s\n", max_str, min_str);
        return 0;
    }

    while(1)
    {
        printf("Enter text: "); 
        read_text(str, sizeof(str), 1);

        if(strncmp(str, "end", 3) == 0) 
            break;
        
        if(strcmp(str, min_str) < 0) 
            strcpy(min_str, str);

        if(strcmp(str, max_str) > 0) 
            strcpy(max_str, str);
    }

    printf("\nMax = %s Min = %s\n", max_str, min_str); 
    return 0;
}