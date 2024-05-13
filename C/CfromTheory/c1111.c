/**
 * Write the power(double a, int b); function that returns the result of a^b. Write a program that reads a float number (e.g., a) and an 
 * integer (e.g., b) and uses the function to display the result of a^b.
*/

#include <stdio.h>

double power(double a, int b);

int main(void)
{
    int exp;
    double base;

    printf("Enter base and exponent: ");
    scanf("%lf%d", &base, &exp);
    printf("%.3f power %d = %.3f\n", base, exp,  power(base, exp));
    return 0;
}

double power(double a, int b)
{
    int i, exp;
    double val;

    val = 1;
    exp = b;

    if(exp < 0)
        exp = -exp;
    for(i = 0; i < exp; i++)
        val *= a;
    
    if(b < 0)
        val = 1/val;
    return val;
}

/**
 * Comments: If we want to output the result in a scientific form of greater precision, we can use %e instead of %f. Notice that the 
 * program does not check extreme conditions such as an overflow case or the use of more efficient algorithms. For example, instead of 
 * executing the loop exp times, we could check if exp is even and, if it is, execute the loop exp/2 times and then square the result. 
 * If it is odd, multiply the result once more with a. For example, if exp is 8, the loop is executed 4 times (a^4)^2. For the same 
 * purpose, the C library provides the pow() function
*/