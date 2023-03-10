#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 81

int main(int argc, char * * argv)
{
    if(argc < 4)
    {
        printf("usage: executable <input-file> <output-file> <word>\n");
        return EXIT_FAILURE;
    }

    FILE * finp = fopen(argv[1], "r");
    if(finp == NULL)
    {
        printf("failed to open input file\n");
        return EXIT_FAILURE;
    }

    FILE * fout =  fopen(argv[2], "w");
    if(fout == NULL)
    {
        fclose(finp);
        printf("failed to open output file\n");
        return EXIT_FAILURE;
    }

    char oneLine[LINE_LENGTH];
    int count = 0;

    while(fgets(oneLine, LINE_LENGTH, finp) != NULL)
    {
        if(strstr(oneLine, argv[3]) != NULL)
        {
            fprintf(fout, "%s\n", oneLine);
        }

        char * chptr = oneLine;
        while (chptr != NULL)
        {
            chptr = strstr(chptr, argv[3]);
            if(chptr != NULL)
            {
                count++;
                // if "eyeye" counts as two "eye"
                chptr++;

                // if "eyeye" counts as one "eye"
                // chptr += strlen(argv[3])
            }
        }
    }

    fprintf(fout, "%d\n", count);
    fclose(finp);
    fclose(fout);
    return EXIT_SUCCESS;


}