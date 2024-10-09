/**
 * Write a program that reads an integer and displays the number of its digits and their sum. For example, if the user enters 
 * 1234, the program should display 4 and 10 (1+2+3+4 = 10).
*/

#include <stdio.h>

int main(void){
    int num, remainder, sum, count;

    count = remainder = sum = 0;

    printf("Enter num: ");
    scanf("%d", &num);

    while(num){
        sum += (num % 10);
        num = num / 10;
        count++;
    }
    printf("Number of digits %d, sum of digits %d\n", count, sum);
    return 0;
}