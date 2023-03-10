#include <stdio.h>
#include <stdlib.h>

int f(int);
void move(int, char, char, char);

int main(int argc, char * * argv)
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
        printf("need one positive integer\n");
        return EXIT_FAILURE;
    }

    printf("f(%d) = %d.\n", n, f(n));
    return EXIT_SUCCESS;

}

int f(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return 2 * f(n - 1) + 1;
}

void move(int disk, char src, char dest, char additional)
{
    if(disk == 1)
    {
        printf("move disk 1 from %c to %c\n", src, dest);
        return;
    }

    move(disk - 1, src, additional, dest);
    printf("move disk %d from %c to %c\n", disk, src, dest);
    move(disk - 1, additional, dest, src);
}