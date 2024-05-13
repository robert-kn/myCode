/**
 * Write two functions that take an integer parameter and return the square and the cube of this number, respectively. Write 
 * a program that reads an integer and uses the functions to display the sum of the number’s square and cube.
*/

#include <stdio.h>

int square(int a);
int cube(int a);

int main(void)
{
    int i, j, k;

    printf("Enter number: ");
    scanf("%d", &i);

    j = square(i);
    k = cube(i);

    printf("sum = %d\n", j+k); 
    return 0;
}

int square(int a)
{
    return a*a;
}

int cube(int a)
{
    return a*a*a;
}