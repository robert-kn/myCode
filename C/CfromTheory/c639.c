/**
 * Write a program that reads an integer N > 3 and calculates the result of the 
 * following math expression. The program should force the user to enter an 
 * integer greater than 3.
 * 
 * num = 1/1 + 1/2 + 1/3 + 1/4 + ... 1/N
*/

#include <stdio.h>

int main(void){

    int num, i;
    double sum, numerator;

    do{
        printf("Enter num > 3: ");
        scanf("%d", &num);

    } while(num <= 3);

    sum = 0;
    numerator = 1;

    for(i = 1; i <= num; i++){
        sum += (numerator/i);
        numerator = -numerator;
    }

    printf("Sum is %e\n", sum);
    return 0;
}