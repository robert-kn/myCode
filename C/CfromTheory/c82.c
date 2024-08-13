/**
 * Write a program that reads two integers, stores them in two variables, declares two 
 * pointers to them, and displays the memory addresses of both 
 * variables, the content of both pointers, as well as their memory addresses.
*/

#include <stdio.h>

int main(void){
    int *ptr1, *ptr2, num1, num2;
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    printf("Num1 address = %p\n", ptr1);
    printf("Num2 address = %p\n", ptr2);
    ptr1 = &num1;
    ptr2 = &num2;
    printf("Addr num1 = %p, Addr num2 = %p\n", ptr1, ptr2);
    return 0;
}