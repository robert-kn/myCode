/**
 * Write a program that reads an integer in [0, 255] continuously and displays it in binary. For example, if the user enters 32, 
 * the program should display 00100000. For any value out of [0, 255] the program should terminate.
*/

#include <stdio.h>

int main(void){
    int num, i;

    printf("Enter num: ");
    scanf("%d", &num);

    while(1){
        if(num < 0 || num > 255)
            break;
        
        for(i = 7; i >= 0; i--){
            if((num >> i) & 1)
                printf("1");
            else
                printf("0");
        }
        printf("\n");
        printf("Enter num: ");
        scanf("%d", &num);
    }
    return 0;
}