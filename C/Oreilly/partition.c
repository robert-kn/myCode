#include <stdio.h>
#include <stdlib.h>

int f(int);

int main(int argc, char * argv[])
{
    int n;
    if(argc < 2)
    {
        printf("usage: executable integer\n");
        return EXIT_FAILURE;
    }

    n = (int) strtol(argv[1], NULL, 10);
    if(n <= 0)
    {
        printf("need one positive integer.\n");
        return EXIT_FAILURE;
    }

    printf("f(%d) = %d.\n", n, f(n));
    return EXIT_SUCCESS;
}

int f(int n)
{
    int i;
    int sum = 0;
    if(n == 1)
    {
        return 1; // only one way to partition
    }

    for(i = 1; i < n; i++)
    {
        sum += f(n - 1);
    }

    sum++;
    return sum;
}