/***
 * Write a program that reads 10 integers and stores them in an array only if either: 
 * 
 * a. the current position is even, i.e., 0, 2, 4, ..., and the input number is even or
 * b. the current position is odd, i.e., 1, 3, 5, ..., and the input number is odd.
 * 
 * The program should not accept the values 0 and -1 and prompt the user to enter a new value. Once the insertion of the 
 * numbers is completed, the unassigned elements should be set to -1. The program should display the array elements before 
 * it ends.
*/

#include <stdio.h>

#define SIZE 10

int main(void){

    int i, num, arr[SIZE] = {0};

    for(i = 0; i < SIZE; i++){
        do {
            printf("Enter number: "); 
            scanf("%d", &num);
            if(num == 0 || num == -1)
                printf("Not valid input !!!\n"); 
        } while(num == 0 || num == -1);
        
        if(i & 1){
            if(num & 1)
                arr[i] = num;
        }
        else{
            if(num % 2 == 0)
                arr[i] = num;     
        }
    }
    for(i = 0; i < SIZE; i++)
        if(arr[i] == 0)
            arr[i] = -1;
    
    for(i = 0; i < SIZE; i++)
        printf("arr[%i] value is %i\n", i, arr[i]);
    
    return 0;
}