#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UserDefinedTypes/vector.h"

Vector vector_construct(int, int, int);
void print_vector(char *, Vector);
void vector_writet(char *, Vector);
Vector vector_readt(char *);
void vector_writeb(char *, Vector);
Vector vector_readb(char *);

int main(int argc, char * * argv)
{
    Vector v1 = vector_construct(13, 206, -549);
    Vector v2 = vector_construct(-15, 8726, 1897);
    print_vector("v1", v1);
    print_vector("v2", v2);
    printf("======================================\n");
    vector_writet("outputs/vectort.dat", v1);
    v2 = vector_readt("outputs/vectort.dat");
    print_vector("v1", v1);
    print_vector("v2", v2);

    Vector v3 = vector_construct(2089, -3357, 1234);
    Vector v4 = vector_construct(7658, 0, 1876);
    printf("======================================\n");
    vector_writeb("outputs/vectorb.dat", v3);
    v2 = vector_readb("outputs/vectorb.dat");
    printf("======================================\n");
    print_vector("v3", v3);
    print_vector("v2", v2);
    print_vector("v4", v4);
    return EXIT_SUCCESS;
}

Vector vector_construct(int a, int b, int c)
{
    Vector v;
    v.x = a;
    v.y = b;
    v.z = c;
    return v;
}

void print_vector(char * name, Vector v)
{
    printf("%s is (%d, %d, %d). \n", name, v.x, v.y, v.z);
}

void vector_writet(char * filename, Vector v)
{
    // writet means write to a test file
    FILE * fptr;
    fptr = fopen(filename, "w");
    if(fptr == NULL)
    {
        printf("vector_writet fopen fail\n");
        return;
    }

    fprintf(fptr, "%d %d %d", v.x, v.y, v.z);
    fclose(fptr);
}

Vector vector_readt(char * filename)
{
    //readt means read from a text file
    Vector v = vector_construct(0,0,0);
    FILE * fptr;
    fptr = fopen(filename, "r");
    if(fptr == NULL)
    {
        printf("vector_readt fopen failed\n");
        return v;
    }

    if(fscanf(fptr, "%d %d %d", &v.x, &v.y, &v.z) != 3)
    {
        printf("fprintf failed\n");
    }
    fclose(fptr);
    return v;
}

void vector_writeb(char * filename, Vector v)
{
    // writeb means write to a binary file
    FILE * fptr;
    fptr = fopen(filename, "w"); // "w" same as "wb" in linux
    if(fptr == NULL)
    {
        printf("vector_writeb fopen failed\n");
        return;
    }

    if(fwrite(& v, sizeof(Vector), 1, fptr) != 1)
    {
        printf("fwrite fail\n");
    }
    fclose(fptr);
}

Vector vector_readb(char * filename)
{
    // readb means read from a binary file
    FILE * fptr;
    Vector v = vector_construct(0,0,0);
    fptr = fopen(filename, "r"); // "r" same as "rb" in linux
    if(fptr == NULL)
    {
        printf("Vector_readb fopen failed\n");
        return v;
    }

    if(fread(& v, sizeof(Vector), 1, fptr) != 1)
    {
        printf("fread failed\n");
    }
    return v;
}