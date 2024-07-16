/* To continue the previous exercise, the program should also read the names of the
10 students (less than 100 characters each) and display the final rating in ascending order
of the given grades */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

void sel_sort(char str[][100], double arr[]);
int read_text(char str[], int size, int flag);

int main(void)
{
    char name[SIZE][100]; /* Array of SIZE rows to store the names of the students. Each name[i] can be used as a pointer to the corresponding row. */

    int i;
    double grd[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter name: ");
        read_text(name[i], sizeof(name[i]), 1);

        printf("Enter grade: ");
        scanf("%lf", &grd[i]);
        getchar();
    }
    sel_sort(name, grd);

    printf("\n***** Final Rating *****\n");

    for(i = 0; i < SIZE; i++)
        printf("%s\t%.2f\n", name[i], grd[i]);
    return 0;
}


void sel_sort(char str[][100], double arr[])
{
    char tmp[100];
    int i, j;
    double k;

    for(i = 0; i < SIZE-1; i++)
    {
        for(j = i+1; j < SIZE; j++)
        {
            if(arr[i] > arr[j])
            {
                /* Parallel swapping of grades and names. */
                k = arr[i];
                arr[i] = arr[j];
                arr[j] = k;

                strcpy(tmp, str[j]);
                strcpy(str[j], str[i]);
                strcpy(str[i], tmp);
            }
        }
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