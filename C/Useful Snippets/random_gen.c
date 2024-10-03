#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));
    printf("random number %f\n", ((double) (rand())*3)/(RAND_MAX+1.0));
    return 0;
}