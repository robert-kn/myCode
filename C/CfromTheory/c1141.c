/* Write a function that takes as parameters an array of names and another name. The
function should check if that name is contained in the array. If it is, the function should return
a pointer to the position of that name in the array, otherwise NULL. Write a program that reads
the names of 20 students (less than 100 characters each) and stores them in an array. Then,
it reads another name and uses the function to check if that name is contained in the array. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM 20
#define SIZE 100

char *find_name(char name[][SIZE], char str[]);
int read_text(char str[], int size, int flag);


int main(void)
{
    char *ptr, str[SIZE], name[NUM][SIZE]; /* The name array holds the names of the students */

    int i;

    for(i = 0; i < NUM; i++)
    {
        printf("Enter name: ");
        read_text(name[i], sizeof(name[i]), 1); /* We use the name[i] as a pointer to the respective i row of SIZE characters. */
    }
    printf("Enter name to search: ");
    read_text(str, sizeof(str), 1);

    ptr = find_name(name, str);
    if(ptr == NULL)
        printf("%s is not contained\n", str);
    else
        printf("%s is contained\n", ptr);
    return 0;
}

char * find_name(char name[][SIZE], char str[])
{
    int i;
    for(i = 0; i < NUM; i++)
    {
        if(strcmp(name[i], str) == 0)
            return name[i]; /* name[i] points to the first character of the row that contains the name. */
        return NULL; /* If this point is reached, the name is not found in the array. */
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