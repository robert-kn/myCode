#include <stdio.h>
#include <stdlib.h>

int f(int);

int main(int argc, char * * argv)
{
    int c, n;
    if(argc < 2)
    {
        printf("usage: executable <integer>\n");
        return EXIT_FAILURE;
    }

    n = (int) strtol(argv[1], NULL, 10);
    c = f(n);
    printf("f(%d) = %d.\n", n, c);
    return EXIT_SUCCESS;
}

int f(int num)
{
    if(num <= 0)
    {
        printf("%d must be positive\n", num);
        return -1;
    }
    else if(num == 1)
    {
        return 2; //f(1) = 2
    }
    else if(num == 2)
    {
        return 3; //f(2) = 3
    }

    int a, b;
    a = f(num - 1);
    b = f(num - 2);
    return (a + b);
}