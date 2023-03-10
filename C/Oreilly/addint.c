#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * * argv)
{
    if(argc < 4)
    {
        printf("usage: executable <input_file1> <input_file2> <output_file1>\n");
        return EXIT_FAILURE;
    }

    FILE * fin1;
    FILE * fin2;
    FILE * fin3;

    /* open 2 input files */
    fin1 = fopen(argv[1], "r");
    if(fin1 == NULL)
    {
        printf("failed to open %s", argv[1]);
        return EXIT_FAILURE;
    }

    fin2 = fopen(argv[2], "r");
    if(fin2 == NULL)
    {
        fclose(fin1);
        printf("failed to open %s", argv[2]);
        return EXIT_FAILURE;
    }

    /* open output file */
    fin3 = fopen(argv[3], "w");
    if(fin3 == NULL)
    {
        fclose(fin1);
        fclose(fin2);
        printf("failed to open %s", argv[3]);
        return EXIT_FAILURE;
    }

    int val1;
    int val2;
    int in1ok = 1; /* can still read input from file 1 */
    int in2ok = 1; /* can still read input from file 2 */

    /* continue as slong as one file still has numbers */
    while((in1ok == 1) || (in2ok == 1))
    {
        val1 = 0; //reset the values before reading from files
        val2 = 0;

        if(fscanf(fin1, "%d", &val1) != 1) /* meaning no value could be read from fin1 stream */
        {
            in1ok = 0;
        }

        if(fscanf(fin2, "%d", &val2) != 1) /* meaning no value could be read from fin2 stream */
        {
            in2ok = 0;
        }

        if((in1ok == 1) || (in2ok == 1))
        {
            fprintf(fin3, "%d\n", val1 + val2); /* save the sum */
        }
    }

    /* close the files */
    fclose(fin1);
    fclose(fin2);
    fclose(fin3);



}