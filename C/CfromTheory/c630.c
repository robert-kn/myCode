/**
 * Write a program that reads the prices of a shop’s products continuously until the user enters -1. The program should display 
 * the lowest price, the highest, and the average of those prices within [5, 30], before it terminates. Assume that the highest 
 * price is $100.
*/

#include <stdio.h>

#define HIGHEST 30
#define LOWEST 5

int main(void){
    int count;
    double price, average, low, high, sum;

    high = sum = count = 0;
    low = HIGHEST;

    printf("Enter product price: ");
    scanf("%lf", &price);

    while(1){
        
        if(price >= LOWEST && price <= HIGHEST){
            sum += price;
            count++;
        }
        else if(price == -1)
            break;

        if(price < low)
            low = price;
        if(price > high && price <= HIGHEST)
            high = price;

        printf("Enter product price: ");
        scanf("%lf", &price);
    }
    printf("lowest price was %.2lf, highest price was %.2lf\n", low, high);

    if(count){
        average = sum/count;
        printf("Average price was %.2lf\n", average);
    }
    return 0;
}