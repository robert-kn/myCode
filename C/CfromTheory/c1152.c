/* Sometimes, in math, it is very difficult to prove some problems that seem quite
simple, like the one of the mathematician Lothar Collatz, who first proposed it. Think of a
positive integer n and execute the following algorithm:
a. If it is even, divide it by two (n/2).
b. If it is odd, triple it and add one (3n+1).
Repeat the same process for each produced number and you’ll come to a surprising
result: for any integer you choose, you’ll always end up with …1!!! For example, if we
choose the number 53, the produced numbers are 53 -> 160 -> 80 -> 40 -> 20 -> 10 -> 5
-> 16 -> 8 -> 4 -> 2 -> 1
This math problem, well known as “Collatz conjecture,” remains unsolved, although the
use of computing machines confirms that for any positive integer up to 260, we’ll eventu-
ally reach 1. 

What we are asking from you is not to prove the Collatz conjecture and contest for the
next Fields prize, but only that, to write a recursive function that takes as parameter a posi-
tive integer and displays the produced sequence of numbers. */

#include <stdio.h>

int collatz(int n);

int main(void)
{
    int a;

    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &a);
    } while(a <= 0);

    printf("The result is %d indeed!!!\n", collatz(a));
    return 0;    
}

int collatz(int n)
{
    printf("%d\n", n);

    if(n == 1)
        return 1;
    else if(n & 1)
        return collatz(3*n+1);
    else
        return collatz(n/2);
}

/* Comments: Execute the program for several positive integers. The result is amazing,
indeed. You’ll always reach 1. */