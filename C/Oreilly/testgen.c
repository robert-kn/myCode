#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE 100

int main(int argc, char * * argv)
{
    if(argc < 2)
    {
        printf("need a positive integer\n");
        return EXIT_FAILURE;
    }

    int num = strtol(argv[1], NULL, 10);

    if(num <= 0)
    {
        printf("need a positive integer\n");
        return EXIT_FAILURE;
    }

    /* the function srand sets the seed. Seeding is used to initialise the random number generator. Linux 
    has a function time which returns the number of seconds since midnight january 1st 1970. When used with srand
    the seed changes every second */
    srand(time(NULL));

    int count;

    for(count = 0; count < num; count++)
    {
        /* the function rand returns a number between 0 and the largest integer. On its own it will return an
        unpredictable integer. You can increase the randomness by giving a seed. The seed is used to initialise
        the random number generator. Supplying the same seed in two different runs of the program, then the will 
        generate the same sequence of numbers. If the seed changes the sequence also changes */
        printf("%d\n", rand() % RANGE);
    }

    return EXIT_SUCCESS;

}
