#include <stdio.h>
#include <stdlib.h>

int f(int, int);

int main(int argc, char * * argv)
{
    int deltax, deltay;
    int c;
    if(argc < 3)
    {
        printf("usage: executable integer integer\n");
        return EXIT_FAILURE;
    }
    deltax = (int) strtol(argv[1], NULL, 10);
    deltay = (int) strtol(argv[2], NULL, 10);

    if((deltax < 0) || (deltay < 0))
    {
        printf("need 2 positive integers.\n");
        return EXIT_FAILURE;
    }

    c = f(deltax, deltay);
    printf("f(%d, %d) = %d\n", deltax, deltay, c);
    return EXIT_SUCCESS;
}

int f(int dx, int dy)
{
    if((dx == 0) || (dy == 0))
    {
        return 1;
    }

    return f(dx - 1, dy) + f(dx, dy - 1);
}