#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 81

int main(int argc, char * * argv)
{
    if(argc < 2)
    {
        printf("usage: executable <file-name>\n");
        return EXIT_FAILURE;
    }

    FILE * fptr = fopen(argv[1], "r");

    if(fptr == NULL)
    {
        printf("Failed to open %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    int numLine = 0;

    char oneline[MAX_LINE_LENGTH];

    while(fgets(oneline, MAX_LINE_LENGTH, fptr) != NULL)
    {
        numLine++;
    }

    fclose(fptr);
    printf("The file has %d lines.\n", numLine);
    return EXIT_SUCCESS;

}