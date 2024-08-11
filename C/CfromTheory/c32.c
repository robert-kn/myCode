/**
 * Write a program that reads two integers and displays their sum, difference, product, and the result of 
 * their division.
 */

#include <stdio.h>

int main(void)
{
    int i, j;
    printf("Enter 2 integers (the second should not be 0):");
    scanf("%d%d", &i, &j);
    printf("Sum:%d Diff:%d Prod:%d Div:%f\n", i+j, i-j, i*j, (double)i/j); /* Cast i to double, in order to display the decimal part of the division. */
    return 0;
}

/**
 * Comments: If the user enters 0 as the second integer, the program won’t perform the
division, since division by 0 is impossible. A typical response is the abnormal program
termination. This can be avoided with the use of the if statement, as we’ll see in Chapter 5.
 */