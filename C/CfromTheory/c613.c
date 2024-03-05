/**
 * Write a program that reads two integers and displays the sum of the integers between them. For example, if the user enters 3 
 * and 8, the program should display 22 because 4+5+6+7 = 22. The program should check which one of the two input numbers is the 
 * greater and act accordingly.
*/

#include <stdio.h>

int main(void){
    int num1, num2, count, order;
    count = order = 0;
    printf("Enter two integers: ");
    scanf("%d%d", &num1, &num2);

    if(num1 < num2){
        order++;
        num1++;
        for(; num1 < num2; num1++)
            count += num1;
    }
    else{
        num2++;
        for(; num2 < num1; num2++)
            count += num2;
    }

    if(order)    
        printf("sum of numbers between %d and %d is %d\n", num1, num2, count);
    else
        printf("sum of numbers between %d and %d is %d\n", num2, num1, count);
    
    return 0;
    
}