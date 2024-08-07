/* Write a macro that calculates the greater of two numbers. Write a program that
reads four integers and uses the macro to display the greatest. */

#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int main(void)
{
    int i, j, k, l;
    printf("Enter numbers: ");
    scanf("%d%d%d%d", &i, &j, &k, &l);
    printf("Max = %d\n", max(max(max(i, j), k), l));
    return 0;
}

/* The preprocessor expands the macros from the inner to the outer. Notice, that
there are other alternatives, for example, we could write max(max(i, j), max(k, l));. */