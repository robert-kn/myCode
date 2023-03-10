/* reads one word at a time from a stream */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 6

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
    printf("Failed to open file\n");
    return EXIT_FAILURE;
}

char buffer[MAXSIZE];

while(fscanf(fptr, "%5s", buffer) == 1) // reads one word at a time
{
    printf("%s\n", buffer);
}

fclose(fptr);
return EXIT_SUCCESS;
}