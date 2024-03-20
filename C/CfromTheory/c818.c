/**
 * Write a program that reads the daily temperatures of January and stores them in an array. Then, the program should read a 
 * temperature and display the first day number with a temperature less than this. Use pointer arithmetic to process the array.
*/

#include <stdio.h> 

#define SIZE 31

int main(void) {
    int i;
    double temp, arr[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter temperatures: ");
        scanf("%lf", arr+i); /* arr+i is equivalent to &arr[i]. */
    }

    printf("Enter temperature to check: ");
    scanf("%lf", &temp);

    for(i = 0; i < SIZE; i++)
    {
        if(*(arr+i) < temp)
            break;
    }

    if(i == SIZE)
        printf("No temperature less than %.1f\n", temp);
    else
        printf("The first temperature less than %.1f was %.1f in day %d\n", temp, *(arr+i), i+1);
    
    return 0;
}