/* Write a program that reads 20 names (less than 100 characters each), stores them
in an array, and uses an array of pointers to display them in alphabetical order. As noted below this algorithm
wastes space because of using a 2 dimensional array which does utilise of of all space per row.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 20

int read_text(char str[], int size, int flag);

int main(void)
{
    char *temp, *ptr[SIZE], str[SIZE][100];
    int i, j;

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter name: ");
        read_text(str[i], sizeof(str[i]), 1);
        ptr[i] = str[i]; /* The elements of the array point to the input strings. */
    }
    for(i = 0; i < SIZE-1; i++)
    {
        for(j = i+1; j < SIZE; j++)
        {
            /* If the string pointed to by ptr[j] is less than the string pointed to by ptr[i], swap the respective pointers. */
            if(strcmp(ptr[j], ptr[i]) < 0)
            {
                temp = ptr[j];
                ptr[j] = ptr[i];
                ptr[i] = temp;
            }
        }
    }
    for(i = 0; i < SIZE; i++)
        printf("%s\n", ptr[i]);
    return 0;
}

/* Comments: The main reason we added this exercise is to show you how useful an array of
pointers might be. When two strings must be swapped, it is the respective pointers that are
swapped, not the strings. As a result, we gain in performance. The sorting algorithm we used
is called selection sort and it will be discussed in Chapter 12. The “negative” point in this solu-
tion is the potential waste of space. Each row of str allocates 100 characters, even if the string
contains less. In Chapter 14 and the exercise C.14.8, you’ll see a more efficient way where the
exact memory needed is dynamically allocated instead of using a fixed two-dimensional array.*/


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