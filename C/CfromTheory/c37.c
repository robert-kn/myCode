/* Continuing the previous exercise, write a program that reads three floats, stores
them in three variables, and rotates them one place right. For example, if the user enters
the numbers 1.2,3.4, and 5.6 and they are stored in variables d1, d2, and d3, the program 
should rotate their values one place right, so that d1, d2, and d3 become 5.6, 1.2, and 3.4,
respectively. */

#include <stdio.h>

int main(void)
{
    double d1, d2, d3, temp;
    printf("Enter numbers: ");
    scanf("%lf%lf%lf", &d1, &d2, &d3);
    temp = d1;
    d1 = d2;
    d2 = temp;
    temp = d3;
    d3 = d1;
    d1 = temp;
    printf("%f %f %f\n", d1, d2, d3);
    return 0;
}