/**
 * Write a program that reads an integer continuously and displays the word Hello a number of times equal to the input integer. 
 * If the user enters a negative number, the insertion of integers should end and the program should display the total number 
 * of the displayed Hello. Use only while loops.
*/

#include <stdio.h>

int main(void){
    int num, count, i;

    i = count = 0;

    printf("Enter integer: ");
    scanf("%d", &num);

    while(num >= 0){

        while(i < num){
            printf("Hello\n");
            i++;
            count++;
        }

        i = 0;
        printf("Enter integer: ");
        scanf("%d", &num);
    }

    printf("Total number of Hello printed %d\n", count);
    return 0;
}