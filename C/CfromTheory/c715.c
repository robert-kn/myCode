/***
 * Write a program that reads an integer and displays the digits that appear more than once and the number of their appearances. 
 * For example, if the user enters 1868, the program should display that digit 8 appears twice. If no digit appears more than once, the 
 * program should display a related message.
*/

#include <stdio.h> 

int main(void)
{
    int i, rem, flag, dig_times[10] = {0}; /* This array holds the appearances of each digit. For example, dig_times[0] indicates how many times digit 0 appears. */
    printf("Enter number: ");
    scanf("%d", &i);
    if(i == 0) /* Check if 0 is entered. */
        dig_times[0] = 1; 
        
    while(i){
        rem = i%10; 
        if(rem < 0)
            rem = -rem;
        dig_times[rem]++;
        i /= 10; 
    }
    flag = 0;
    for(i = 0; i < 10; i++){
        if(dig_times[i] > 1) {
            printf("Digit %d appears %d times\n", i, dig_times[i]);
            flag = 1; 
        }
    }
    if(flag == 0)
        printf("No digit appears multiple times\n"); 
    return 0;
}