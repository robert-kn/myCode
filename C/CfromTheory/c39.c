/**
 * Write a program that reads two positive float numbers and displays the sum of their integer and decimal parts. 
 * Use only two double variables. For example, if the user enters 1.23 and 9.56, the program should display 10 
 * and 0.79.
*/

#include <stdio.h>

int main(void){
    float num1, num2, sum;
    printf("Enter two float numbers: \n");
    scanf("%f %f", &num1, &num2);
    sum = num1 + num2;
    printf("int part %d; float part is %f\n", (int) sum, sum - (int) sum);
    return 0;
}