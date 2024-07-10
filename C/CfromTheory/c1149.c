/* Write a recursive function that takes as parameter an integer (e.g., N) and returns
the Nth term of the Fibonacci sequence, using the formula F(N) = F(N-1) + F(N-2), where
F(0) = 0 and F(1) = 1. Write a program that reads an integer N between 2 and 40 and uses
the function to display the Nth term. */

#include <stdio.h>

unsigned int fib(int num);

int main(void)
{
    int num;

    do
    {
        printf("Enter a number between 2 and 40: ");
        scanf("%d", &num);
    } while(num < 2 || num > 40);

    printf("F(%d) = %d\n", num, fib(num));
    return 0;
}

unsigned int fib(int num)
{
    if(num == 0)
        return 0;
    else if(num == 1)
        return 1;
    else    
        return fib(num-1) + fib(num-2);
}

/* Comments: This recursive solution of printing Fibonacci numbers is not so efficient because
the recalculation of lower terms is repeated. For example, fib(5) = fib(4) + fib(3).
To calculate fib(4), fib(3) and fib(2) are calculated. When the second term fib(3) is
calculated, the same calculations are repeated. As a result, the execution time of fib()
is significantly increased. Comparing the solutions, the code described earlier in C.11.35
is executed faster. */