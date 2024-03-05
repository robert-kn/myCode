/**
 * Write a program that reads a positive integer and displays the largest positive integer n for which the sum 
 * 1^2 + 2^2 + 3^2 +...+ n^2 is less than the given number.
*/

#include <stdio.h>

int main(void){
    int num, i, sum;
    sum = i = 0;

    printf("Enter num: ");
    scanf("%d", &num);

    while(1){
        if(num < 0 || num == 0)
            break;
        else{
            while(sum < num){
                ++i;
                sum += (i * i);
            }
            printf("Number entered %d, largest positive integer which is < than number entered %d\n", num, sum);
            sum = i = 0; 
            printf("Enter num: ");
            scanf("%d", &num);
        }
    }
    
}