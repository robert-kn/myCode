#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector vector_construct(int, int, int);

void printVector(Vector);

int main(int agrc, char * * argv)
{
    Vector v1 = vector_construct(2,3,4);

    printVector(v1);

    return EXIT_SUCCESS;
}

void printVector(Vector v)
{
    printf("The vector is v1 (%d, %d, %d).\n", v.x, v.y, v.z);
}

Vector vector_construct(int a, int b, int c)
{
    Vector v;
    v.x = a;
    v.y = b;
    v.z = c;
    return v;
}