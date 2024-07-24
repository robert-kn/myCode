/* Modify the previous program and use a pointer to read and display the students’ data. Don’t declare the i variable. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

struct student
{
    char name[50]; 
    int code;
    float grd;
};

int read_text(char str[], int size, int flag);

int main(void)
{
    struct student *ptr, stud[SIZE];

    for(ptr = stud; ptr < stud+SIZE; ptr++) /* ptr is increased to point to the next structure. */
    {
        printf("\nEnter name: ");
        read_text(ptr->name, sizeof(ptr->name), 1);

        printf("Enter code: ");
        scanf("%d", &ptr->code);

        printf("Enter grade: ");
        scanf("%f", &ptr->grd);

        printf("\nN: %s C: %d G: %.2f\n", ptr->name, ptr->code, ptr->grd);
        getchar();
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