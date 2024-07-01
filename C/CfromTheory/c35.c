/* Write a program that reads a positive float number and displays the previous and next integers.*/

#include <stdio.h>

int main(void)
{
    float i;
    printf("Enter positive number: ");
    scanf("%f", &i);
    printf("%f is between %d and %d\n", i, (int)i, (int)(i+1));
    return 0;
}