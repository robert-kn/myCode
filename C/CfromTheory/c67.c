/**
 * Write a program that reads an integer in [0, 170] and displays its factorial. 
 * The facto- rial of a positive integer n, where n ≥ 1, is defined as 
 * 1 × 2 × 3 × ... × n, while the factorial of 0 equals 1 (0! = 1).
*/

#include <stdio.h>

int main(void){
    int num, i;
    double fact;
    printf("Enter number in interval [0, 170]: ");
    scanf("%d", &num);

    if(num >= 0 && num <= 170){
        fact = 1;
        for(i = 1; i <= num; i++){
            fact *= i;
        }
        printf("Factorial of %d is %e\n", num, fact);
    }
    else{
         printf("Number should be within interval [0, 170]\n");
    }
}