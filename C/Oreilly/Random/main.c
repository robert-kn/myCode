#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysort.h"

int main(int argc, char * * argv)
{
    if(argc != 2)
    {
        return EXIT_FAILURE;
    }

    int number = strtol(argv[1], NULL, 10);
    int ind;
    for(ind = 0; ind < number; ind++)
    {
        int val;
        scanf("%d", &val);
        printf("%d\n", val);
    }
    return EXIT_SUCCESS;
}