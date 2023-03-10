#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RANGE 10000

void printArray(int *, int);

int comparefunc(const void * arg1, const void * arg2);


int main(int argc, char * * argv)
{
    if(argc != 2)
    {
        return EXIT_FAILURE;
    }

    int size = strtol(argv[1], NULL, 10);
    if(size <= 0)
    {
        return EXIT_FAILURE;
    }

    int * arr = malloc(size * sizeof(int));

    if(arr == NULL)
    {
        printf("malloc failed\n");
        return EXIT_FAILURE;
    }

    int i;

    srand(time(NULL));

    for(i = 0; i < size; i++)
    {
        arr[i] = rand() % RANGE;
    }

    printArray(arr, size);

    qsort(arr, size, sizeof(int), comparefunc);

    printArray(arr, size);

    free(arr);

    return EXIT_SUCCESS;
}

void printArray(int * arr, int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", * (arr + i));
    }
    printf("\n");
}
