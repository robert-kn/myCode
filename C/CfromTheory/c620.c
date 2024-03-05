/**
 * Write a program that reads an integer and displays a message to indicate whether it is a prime number or not. It is 
 * reminded that a prime number is any integer greater than 1 with no divisor other than 1 and itself.
*/

#include <stdio.h>

int main(void){
    int i, num;

    printf("Enter number (>1): ");
    scanf("%d", &num);

    if(num > 1){
        if(num % 2 == 0){
            if(num == 2)
                printf("%d is a prime number\n", num);
            else
                printf("%d is not a prime number\n", num);
            return 0;
        }

        for(i = 3; i <= num/2; i+=2){
            if(num % i == 0){
                printf("%d is not a prime\n", num);
                return 0;
            }
        }

        printf("The number %d is prime\n", num);
    }
    else
        printf("Error: Not valid number\n");
    return 0;
}