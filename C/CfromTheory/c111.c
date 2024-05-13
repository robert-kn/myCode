/**
 * In the following program, which one of the scanf() and printf() functions may change the value of a;
*/

#include <stdio.h>

int main(void)
{
    int a;
    scanf("%d", &a);
    printf("Value: %d\n", a);
    return 0;
}

/**
 * Answer: scanf() may change the value of a, because the passing argument is its address. 
 * On the other hand, printf() cannot change a, because the passing argument is its value.
 * 
*/