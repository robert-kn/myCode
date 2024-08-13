/**
 * Write a program that declares an array of 10 floats, assigns random values within 
 * [0, 1] to its elements, and displays their
 * average. To remember how to use srand() and rand()
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

int main(void){
    float arr[SIZE], average, sum = 0;
    int i;

    srand(time(NULL));

    for(i = 0; i < SIZE; i++){
        arr[i] = (double) rand()/RAND_MAX;
        sum += arr[i];
    }
    for(i = 0; i < SIZE; i++)
        printf("%f\n", arr[i]);
    average = sum/10;
    printf("The average of the above values is %f (rounded figure %.3f)\n", average, average);
    return 0;
}