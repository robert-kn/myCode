/* Write a function that takes as parameter an integer (e.g., N) and calculates the Nth
term of the Fibonacci sequence, according to the formula F(N) = F(N-1)+ F(N-2), where
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

    printf("F(%d) = %u\n", num, fib(num));
    return 0;
    
}

unsigned int fib(int num)
{
    unsigned int term1, term2, sum;

    term1 = 1;
    term2 = 0;
    while(num > 1)
    {
        sum = term1 + term2;
        term2 = term1;
        term1 = sum;
        num--;
    }
    return sum;
}

/* Comments: Given that F(N) = F(N-1)+ F(N-2), the first terms are 0, 1, 1, 2, 3, 5, 8, 13,
21, 34, 55, 89, 144, …. For example, F(7) = 13, which is the sum of F(6) and F(5). To cal-
culate the value of a term, we store into term1 the last sum, while in term2 the previous one. */