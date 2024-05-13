/**
 * Write a void function that generates a random number from 0 to 1 with two decimal digits and uses a proper parameter to return it. 
 * Write a program that calls the function and displays the return value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void make_rand(double * p);

int main(void)
{
    double d;

    make_rand(&d);
    printf("%.2f\n", d);
    return 0;
}

void make_rand(double *p)
{
    int i;
    srand(time(NULL)); /* It is reminded that srand() together with time() are used to generate random positive integers, each time the program runs. */
    i = rand()%101; /* rand() returns a random integer which is constrained in [0, 100]. */
    *p = i/100.0; /* This division constrains the value within [0, 1] with two decimal digits. */
}

/**
 * Comments: Since the return type is void we use a pointer parameter, so that the function can return the value.
*/