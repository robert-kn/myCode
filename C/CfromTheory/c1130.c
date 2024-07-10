/* What is the output of the following program? */

#include <stdio.h>

void test(int *arg);

int var = 100;

int main(void)
{
    int *ptr, i = 30;

    ptr = &i;
    test(ptr);
    printf("%d\n", *ptr);
    return 0;
}

void test(int *arg)
{
    arg = &var;
}

/* Answer: You answered 100, didn’t you? Basket Case from Green Day, play it loud. Let’s see
the trap.
Since the value of ptr and not its address is passed to test(), any change in the value
of arg does not affect ptr. Therefore, the program displays 30. */