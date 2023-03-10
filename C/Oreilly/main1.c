#include "mystring.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_SIZE 1000

int main(int argc, char * argv[]){
    if(argc != 4){
        printf("usage: %s command input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE * inpfptr = fopen(argv[2], "r");

    if(inpfptr == NULL){
        printf("unable to open file %s\n", argv[2]);
        fclose(inpfptr);
        return EXIT_FAILURE;
    }

    FILE * outfptr = fopen(argv[3], "w");

    if(outfptr == NULL){
        printf("unable to open file %s\n", argv[3]);
        fclose(outfptr);
        return EXIT_FAILURE;
    }

    int num_lines = 0;

    char buffer[LINE_SIZE];

    while(fgets(buffer, LINE_SIZE, inpfptr) != NULL){
        num_lines++;
    }

    fseek(inpfptr, 0, SEEK_SET);

    char * * lines = malloc(sizeof(char *) * num_lines);

    int i;

    for(i = 0; i < num_lines; i++)
    {
        if(feof(inpfptr))
        {
            printf("not enough num lines in file\n");
            fclose(inpfptr);
            fclose(outfptr);
            return EXIT_FAILURE;

        }

        lines [i] = malloc(sizeof( char ) * LINE_SIZE);
        fgets(lines[i], LINE_SIZE, inpfptr); 
    }

    fclose(inpfptr);

    int total_length = 0;

    for(i = 0; i < num_lines; i++)
    {
        total_length += my_strlen(lines[i]);
    }

    if(strcmp(argv[1], "strlen") == 0)
    {
        for(i = 0; i < num_lines; i++)
        {
            fprintf(outfptr, "length: %d\n", my_strlen(lines[i]));
        }
        fprintf(outfptr, "total length: %d\n", total_length);
    }

    if(strcmp(argv[1], "countchar") == 0)
    {
        for(i = 0; i < num_lines; i++)
        {
            fprintf(outfptr, "count(%c): %d\n", lines[i][0], my_countchar(lines[i], lines[i][0]));
        }
    }

    if(strcmp(argv[1], "strupper") == 0)
    {
        for(i = 0; i < num_lines; i++)
        {
            my_strupper(lines[i]);
            fprintf(outfptr, "%s", lines[i]);
        }
    }

    for(i = 0; i < num_lines; i++)
    {
        free(lines[i]);
    }

    free(lines);
    fclose(outfptr);
    return EXIT_SUCCESS;
}