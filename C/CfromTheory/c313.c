/**
 * Write a program that reads a positive integer and rounds it up or down depending on the last digit. For
 * example, if the user enters 12, the program should display 10. If the input number is 3, the program 
 * should display 0, while if it is 455, the program should display 460.
*/

#include <stdio.h>

int main(void){
    int i;
    float j;

    printf("Enter positive number: ");
    scanf("%d", &i);
    
    i =  i + 5;
    j = (float) i/10;
    i = (int) j * 10; /* cut off the last digit */
    printf("%d\n", i);
    return 0;
}