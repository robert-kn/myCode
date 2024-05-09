#include <stdio.h>

#define MAX 10

int main(void)
{
    int i, count;
    count = 0;

    for(i = 1; i <= MAX; i++)
    {
        if(i % 3 == 0 || i % 5 == 0)
            count += i;
            printf("count is %d\n", count);
    }
    printf("Sum of multiples of 3 and 5 between 1 and 10 is %d\n", count);
}