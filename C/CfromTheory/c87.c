/**
 * Write a program that uses two pointers to read two float numbers first and then to swap the values they point to. Then, use 
 * the same pointers to output the greater value.
*/

#include <stdio.h>

int main(void){
    double *ptr1, *ptr2, num1, num2, tmp;

    /* the pointers should be initialised before being used in scanf() */
    ptr1 = &num1;
    ptr2 = &num2;

    printf("Enter two floating point numbers: ");
    scanf("%lf%lf", ptr1, ptr2);

    tmp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = tmp;

    if(*ptr1 > *ptr2)
        printf("%lf is > %lf\n", *ptr1, *ptr2);
    else
        printf("%lf is > %lf\n", *ptr2, *ptr1);
    return 0;
}