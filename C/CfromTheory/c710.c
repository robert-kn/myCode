/**
 * The purpose of the following program is to generate 10 random integers, store them in an array, and then store in the freq frequency array, the number of occurrences of each number from 0 to 9. Can you find any errors in 
 * the program? If yes, correct them.
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define SIZE 10

int main(void){
    int i, num, arr[SIZE], freq[SIZE] = {0};

    srand(time(NULL));

    for(i = 0; i < SIZE; i++)
        arr[i] = rand();

    for(i = 0; i < SIZE; i++){
        if(arr[i] >= 0 && arr[i] <= 9){
            num = arr[i];
            freq[num]++;
        }
    }

    printf("\nNumber occurrences\n");
    for(i = 0; i < SIZE; i++)
        printf("%d appears %d times\n", i, freq[i]);

    return 0;
}