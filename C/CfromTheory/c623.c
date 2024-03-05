/**
 * Write a program that reads an integer that corresponds to a number of lines. The program should display in each line 
 * a number of '*' equal to the line number. For exam- ple, if the user enters 5 the program should display:
 * *
 * *
*/

#include <stdio.h>

int main(void){
    int i, j, number;
    printf("Enter number: ");
    scanf("%d", &number);

    for(i = 1; i <= number; i++){
        printf("\n");
        for(j = 1; j <= i; j++)
            printf("* ");
    }
    printf("\n");
    return 0;
}