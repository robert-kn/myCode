#include <stdio.h>
#include <stdlib.h>

int comparefunc(const void * arg1, const void * arg2);

int main(int argc, char * * argv)
{
    if(argc < 3)
    {
        printf("usage: executable <input-file> <output-file>");
        return EXIT_FAILURE;
    }

    FILE * finp = fopen(argv[1], "r");
    if(finp == NULL)
    {
        printf("Failed to open input file\n");
        return EXIT_FAILURE;
    }

    int count = 0;
    int val;

    while(fscanf(finp, "%d", &val) == 1)
    {
        count++;
    }

    fseek(finp, 0, SEEK_SET);

    int * arr = malloc(sizeof(int) * count);

    if(arr == NULL)
    {
        fclose(finp);
        printf("malloc call failed\n");
        return EXIT_FAILURE;
    }

    int index = 0;

    while(fscanf(finp, "%d", &val) == 1)
    {
         * (arr + index) = val;
         index++; 
    }

    qsort(& arr[0], count, sizeof(int), comparefunc);

    fclose(finp);

    FILE * fout = fopen(argv[2], "w");

    if(fout == NULL)
    {
        free(arr);
        printf("Failed to open output file\n");
        return EXIT_FAILURE;
    }

    for(index = 0; index < count; index++)
    {
        fprintf(fout, "%d\n", arr[index]);
    }

    fclose(fout);
    free(arr);
    return EXIT_SUCCESS;

    
}

int comparefunc(const void * arg1, const void * arg2)
{
    const int * ptr1 = (const int *) arg1; // cast type
    const int * ptr2 = (const int *) arg2;

    const int val1 = * ptr1; //get the value from the address
    const int val2 = * ptr2;

    if(val1 < val2)
    {
        return -1;
    }
    else if(val1 == val2)
    {
        return 0;
    }
    else{
        return 1;
    }
}