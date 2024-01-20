/**
 * Write a program similar to C.2.6 for a three-digit positive value.
*/
#include <stdio.h>

int main(void){
    int sum = 0, j = 0, num, copy;
    printf("Enter 3 digit number: ");
    scanf("%d", &num);
    copy = num;

    while(j < 3){
        sum += (num % 10);
        num = num/10;
        j++;
    }

    printf("Number = %d and sum = %d\n", copy, sum);
}
