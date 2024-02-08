/**
 * Write a program that reads a two-digit positive integer and displays the reversed number. For example, if 
 * the user enters 72, the program should display 27. Use one integer variable.
*/

#include <stdio.h>

int main(void){
    int i, copy;
    printf("Enter number between 10 and  99: ");
    scanf("%d", &i);
    copy = i;
    i = 10*(i%10) + i/10;
    printf("input number was %d; reversed number is %d\n", copy, i);
    return 0;
}