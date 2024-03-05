/**
 * Write a program that reads a positive integer n and verifies the math formula: 1 + 3 + 5 + ... + (2n-1) = n^2.
*/

#include <stdio.h>

int main(void){
    int num, i, sum;
    sum = 0;
    
    printf("Enter number > 0: ");
    scanf("%d", &num);

    if(num <= 0){
        printf("Number must be > 0\n");
        return 1;
    }
    else{
        for(i = 1; i <= 2*num-1; i += 2)
            sum += i;
    }
    if(sum == num*num)
        printf("value of sum (%d) and num squared (%d) are equal\n", sum, num*num);
    else
        printf("value of sum (%d) and num squared (%d) are not equal\n", sum, num*num);
    return 0;
}