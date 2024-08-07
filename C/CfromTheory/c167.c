/* Write a macro that calculates the greatest of three numbers. Write a program that
reads three double numbers and uses the macro to display the greatest. */

#include <stdio.h>

#define max(a, b, c) ((a) >= (b) && (a) >= (c) ? (a) : (b) > (a) && (b) > (c) ? (b) : (c))

int main(void)
{
    double i, j, k;
    printf("Enter numbers: ");
    scanf("%lf%lf%lf", &i, &j, &k);
    printf("Max = %f\n", max(i, j, k));
    return 0;
}