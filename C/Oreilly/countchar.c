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
    int ch;
    int counter = 0;

    fptr = fopen(argv[1], "r");

    if(fptr == NULL)
    {
        printf("fopen failed");
        return EXIT_FAILURE;
    }

    do{
        ch = fgetc(fptr);
        if(ch != EOF)
        {
            counter++;
        }
    }while(ch != EOF);

    fclose(fptr);
    printf("The file %s has a total of %d characters\n", argv[1], counter);
    return EXIT_SUCCESS;
}