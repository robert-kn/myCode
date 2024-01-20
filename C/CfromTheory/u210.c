/**
 * Write a program that assigns two positive values into two float variables and displays the integer part of their 
 * division and the fractional part. For example, if they are assigned the values 7.2 and 5.4, the program should 
 * display 1 and 1.8, since 7.2 = (1 × 5.4)+1.8.
*/

#include <stdio.h>
#include <math.h>

int main(void){
    float n1, n2;
    printf("Enter first float number: ");
    scanf("%f", &n1);
    printf("Enter second float number: ");
    scanf("%f", &n2);
   
    printf("integer part is %d and fractional part is %.1f\n", (int) (n1/n2), remainder(n1,  n2));
    return 0;
}


