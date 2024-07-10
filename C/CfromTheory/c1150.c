/* What does the following program do? */

#include <stdio.h>

int unknown(int num1, int num2);

int main(void)
{
    int num1, num2, sign;

    printf("Enter numbers: ");
    scanf("%d%d", &num1, &num2);

    sign = 1;
    if((num1 < 0) && (num2 > 0))
    {
        num1 = -num1;
        sign = -1;
    }
    else if((num1 > 0) && (num2 < 0))
    {
        num2 = -num2;
        sign = -1;
    }
    else if((num1 < 0) && (num2 < 0))
    {
        num1 = -num1;
        num2 = -num2;
    }

    if(num1 > num2)
        printf("%d\n", sign*unknown(num1, num2));
    else
        printf("%d\n", sign*unknown(num2, num1));
    return 0;
}

int unknown(int n1, int n2)
{
    if(n2 == 1)
        return n1;
    else    
        return n1 + unknown(n1, n2-1);
}

/* Answer: First, let’s see what the function is doing. Suppose that it is called with arguments
10 and 4. The function returns:
n1 + unknown(n1, n2-1 = 3) =
n1 + n1 + unknown(n1, n2-1 = 2) =
n1 + n1 + n1 + unknown(n1, n2-1 = 1)
The last call of unknown(n1, 1) returns n1, because n2 = 1. Therefore, the function
returns:
n1+n1+n1+n1 = 4*n1 = n2*n1
The if-else-if series finds the sign of the product and the absolute values of the inte-
gers. Next, the if-else statement is used, in order to make the less recursive calls.

As a result, the purpose of this program is to calculate the product of the input numbers
through the use of a recursive function.*/