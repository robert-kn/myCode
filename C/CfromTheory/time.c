#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(void)
{
    int i, num;
    double num2;

    srand(time(NULL));
    for(i = 0; i < 5; i++)
    {
        num = rand()%16+5;
        num2 = (double)rand()/RAND_MAX;
        printf("%d\t%lf\n", num, num2);
    }
    printf("%d\t%d\t%d\n", INT_MAX, INT_MIN, RAND_MAX);
}