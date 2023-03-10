#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * * argv)
{
    if(argc < 2)
    {
        printf("Usage: executable <file_path>\n");
        return EXIT_FAILURE;
    }

    FILE * fptr;
    int val;
    int sum = 0;

    fptr = fopen(argv[1], "r");

    if(fptr == NULL)
    {
        printf("fopen failed");
        return EXIT_FAILURE;
    }

    printf("The name of the fgile is %s", argv[1]);

    while(fscanf(fptr, "%d", &val) == 1)
    {
        printf("%d ", val);
        sum += val;
    }

    fclose(fptr);
    printf("\n The sum is %d\n", sum);
    return EXIT_SUCCESS;
}