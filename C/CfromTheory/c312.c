/**
 * Write a program similar to c311 for a three-digit positive integer.
*/

#include <stdio.h>

int main(void){
    int i, copy;
    printf("Enter number between 100 and 999: ");
    scanf("%d", &i);
    copy = i;
    i = 100*(i%10) + 10*(i%100/10) + i/100;
    printf("input number was %d; reversed number is %d\n", copy, i);
    return 0;
}