#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000

int main(int argc, char * argv[])
{
    if(argc != 2)
    {
        return EXIT_FAILURE;
    }

    char array[ARRAY_SIZE] = {'\0'};

    FILE * fptr = fopen(argv[1], "r");

    if(fptr == NULL)
    {
        return EXIT_FAILURE;
    }

    int len = 0;
    int value;

    while(fscanf(fptr, "%s", array) == 1)
    {
        len++;
        printf("%s\n", array);
    }

    printf("length: %d\n", len);

}