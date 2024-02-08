/**
 * Write a program that reads an integer and displays a message to indicate whether it is even or odd.
*/

#include <stdio.h>
#include <limits.h>

int main(void){
    int num;
    printf("Enter number between %d and %d: ",INT_MIN, INT_MAX);
    scanf("%d", &num);
    if(num & 1)
        printf("odd\n");
    else
        printf("even\n");
    return 0;
}