#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

void printVector(Vector);

void changeVector(Vector *);

int main(int agrc, char * * argv)
{
    Vector v1;
    v1.x = 3;
    v1.y = 6;
    v1.z = -2;

    printVector(v1);

    changeVector(&v1);

    printVector(v1);

    return EXIT_SUCCESS;
}

void printVector(Vector v)
{
    printf("The vector is v1 (%d, %d, %d).\n", v.x, v.y, v.z);
}

void changeVector(Vector * v)
{
    v -> x = 20;
    v -> y = 40;
    v -> z = 60;
    printVector(* v);
}