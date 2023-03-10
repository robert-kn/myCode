#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NUM_CHAR 26

int main(int argc, char * * argv)
{
    if(argc < 3)
    {
        printf("usage: executable <input-file> <output-file>\n");
        return EXIT_FAILURE;
    }

    FILE * finp = fopen(argv[1], "r");
    if(finp == NULL)
    {
        printf("failed to open input file\n");
        return EXIT_FAILURE;
    }

    int charCount[NUM_CHAR] = {0};

    int oneChar;

    do{
        oneChar = fgetc(finp);
        if(isupper(oneChar))
        {
            charCount[oneChar - 'A']++; 
        }
        else if(islower(oneChar))
        {
            charCount[oneChar - 'a']++;
        }
    }while(oneChar != EOF);

    fclose(finp);

    FILE * fout = fopen(argv[2], "w");

    if(fout == NULL)
    {
        printf("failed to open output file\n");
        return EXIT_FAILURE;
    }

    for(int index = 0; index < NUM_CHAR; index++)
    {
        fprintf(fout, "%c: %d\n", index + 'A', *(charCount + index));
    }

    fclose(fout);
    return EXIT_SUCCESS;

} 