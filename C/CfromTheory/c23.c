/**
 * Write a program that declares two integers, assigns to them the values 50 and 20, and displays their sum, difference, product, the precise 
 * result of their division (i.e., 2.5), and the remainder (i.e., 10). To find the remainder use the % operator.
*/


#include <stdio.h>
int main(void){
    int i = 50;
    int j = 20;
    printf("sum = %d, difference = %d, product = %d, division = %.1f, \
     remainder = %d\n", i+j, i-j, i*j, i/(float)j, i%j);
    return 0;
}