/* Write a recursive function that takes as parameter an integer n and returns its
factorial, using the formula n! = n×(n-1)!. The factorial of an integer n, where n >= 1, is the
product of the integers from 1 to n, that is, 1×2×3×...×n. The factorial of 0 is 1 (0!=1). Write
a program that reads a positive integer less than 170 and uses the function to display its
factorial. */

#include <stdio.h>

double fact(int num);

int main(void)
{
    int num;

    do
    {
        printf("Enter a positive integer less than 170: ");
        scanf("%d", &num);
    } while(num < 0 || num > 170);
    printf("Factorial of %d is %e\n", num, fact(num));
    return 0;
}

double fact(int num)
{
    if((num == 0) || (num == 1))
        return 1;
    else
        return num * fact(num-1);
}

/* Comments: Notice that for large values of num the calls to fact() increase; therefore, the
time to calculate its factorial also increases. In that case, the alternative solution with the
for loop in C.6.7 calculates the factorial’s number faster. */