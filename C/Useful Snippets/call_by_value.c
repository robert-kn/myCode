#include <stdio.h>

void test(int * p);

int main(void)
{
    int i = 10;
    test(&i);
    printf("%d\n", i);
    return 0;
}

void test(int * p)
{
    *p = 20;
}