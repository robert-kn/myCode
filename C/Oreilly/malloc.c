#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * * argv)
{
    int * arr2;
    int i;
    int sum = 0;

    if(argc < 2)
    {
        printf("Need to provide some integers as input\n");
        return EXIT_FAILURE;
    }

    arr2 = malloc(argc * sizeof(int));

    if(arr2 == NULL)
    {
        printf("maloc failed\n");
        return EXIT_FAILURE;
    }

    for(i = 1; i < argc; i++)
    {
        *(arr2 + i) = (int) strtol(*(argv + i), NULL, 10);
    }

    printf("The sum of ");

    for(i = 1; i < argc; i++)
    {
        printf("%d ", *(arr2 + i));
        sum += *(arr2 + i);
    }

    printf("is %d\n", sum);
    return EXIT_SUCCESS;
}