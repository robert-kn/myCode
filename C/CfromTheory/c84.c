/**
 * Write a program that uses a pointer to read a float number and display its absolute value.
*/

#include <stdio.h>

int main(void){
    double *ptr, val;
    ptr = &val;
    printf("enter floating point number: ");
    scanf("%lf", &val);

    if(*ptr >= 0)
        printf("%.1f\n", *ptr);
    else
        printf("%.1f\n", -*ptr);
    
    return 0;
}