#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

Vector * vector_construct(int,int,int);
void vector_destruct(Vector *);
void print_vector(Vector *);

int main(int argc, char * * argv)
{
    Vector * v1;
    v1 = vector_construct(3,6,-2);
    if(v1 == NULL)
    {
        return EXIT_FAILURE;
    }
    print_vector(v1);
    vector_destruct(v1);
    return EXIT_SUCCESS;
}

Vector * vector_construct(int a, int b, int c)
{
    Vector * v;
    v = (Vector *) malloc(sizeof(Vector));
    if(v == NULL)
    {
        printf("malloc failed\n");
        return NULL;
    }
    v -> x = a; // (*v).x = a;
    v -> y = b;
    v -> z = c;
    return v;
}

void vector_destruct(Vector * v)
{
    free(v);
}

void print_vector(Vector * v)
{
    printf("The vector is (%d, %d, %d)\n", v->x, v->y, v->z);
}