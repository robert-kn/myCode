#include <stdio.h>

void test(int * p);

int main(void)
{
    int * ptr, i;

    ptr = &i;

    printf("%p\n", ptr);

    test(ptr);
    printf("%p\n", ptr);
    return 0;
}

void test(int * p)
{
    int j;
    p = &j;
}