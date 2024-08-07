/* Write a macro that checks whether a number is odd or even. Write a program that
reads an integer and uses the macro to display whether it is odd or even. */

#include <stdio.h>

#define odd_even(a) (((a) & 1) == 0)

int main(void)
{
    int i;
    printf("Enter number: ");
    scanf("%d", &i);
    
    if(odd_even(i))
        printf("Even\n");
    else
        printf("Odd\n");
    return 0;
}