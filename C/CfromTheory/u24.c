/**
 * Fix the errors in order to run the program and display the sum of a and b.
*/

#include <stdio.h>

#define NUM 30

int main(void)
{
    const int a = 10;
    /*NUM = a+2;*/ /* -->  illegal */
    /*a = NUM/2;*/ /* --> illegal */
    int b = a; 
    printf("%d\n", a+b); 
    return 0;
}