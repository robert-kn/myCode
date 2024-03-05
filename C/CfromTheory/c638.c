/**
 * Write a program that reads integers continuously and displays the square of 
 * the even numbers until the user enters a number in [10, 20]. The program should 
 * display how many positive and negative numbers were entered and how many are in 
 * [300, 500], before it ends. Zero is counted as neither a positive nor a negative 
 * number.
*/

#include <stdio.h>

int main(void){

    int num, cnt, pos, neg;

    cnt = pos = neg = 0;

    do{
        printf("Enter num: ");
        scanf("%d", &num);

        if((num & 1) == 0)
            printf("Square of %d is %d\n", num, num*num);

        if(num > 0){

            pos++;

            if(num >= 300 && num <= 500)
                cnt++;
        }
        else {
            neg++;
        }
    } while(num < 10 || num >  20);

    printf("Positive numbers %d; negative numbers %d;\
    numbers in range [300, 500] %d\n", pos, neg, cnt);

    return 0;


}