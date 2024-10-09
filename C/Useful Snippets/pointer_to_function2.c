#include <stdio.h>

void test(int a);

int main(void){
    void (*ptr)(int a); /* ptr is declared as a pointer to a function, which takes an integer parameter and returns nothing */

    ptr = test;        /* ptr points to the address of test() */
    (*ptr)(10);        /* call the function that ptr points to */
    return 0;
}

void test(int a)
{
    printf("%d\n", 2*a);
}