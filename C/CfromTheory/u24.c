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