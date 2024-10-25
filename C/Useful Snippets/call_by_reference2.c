#include <stdio.h>

void test(int **arg);

int var = 100;

int main(void)
{
    int *ptr, i = 30;

    ptr = &i;
    test(&ptr); /* The value of &ptr is the memory address of ptr, which points to the address of i. So, the type of the argument is a pointer to a pointer to an integer and matches the function declaration. */
    printf("%d\n", *ptr);
    printf("%p\n", ptr);
    return 0;
}

void test(int **arg)
{
    printf("%p\n", arg);
    *arg = &var;
}