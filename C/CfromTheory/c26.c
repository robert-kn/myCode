#include <stdio.h>

/**
 * Write a program that assigns a two-digit positive value to an integer variable and displays the sum of its digits.
 * For example, if the assigned value is 35, the program should display 8.
*/
int main(void){
    int sum = 0, j = 0, i = 46, copy = i;

    while(j < 2){
        sum += (i % 10);
        i = i/10;
        j++;
    }

    printf("Number = %d and sum = %d\n", copy, sum);
}