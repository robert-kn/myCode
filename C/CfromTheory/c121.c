/* Write a function that searches for a number in an array of doubles. If the number
is stored, the function should return the number of its occurrences and the position of its
first occurrence, otherwise -1. Write a program that reads up to 100 doubles and stores
them in an array. If the user enters -1, the insertion of numbers should terminate. Then,
the program should read a double number and use the function to display its occurrences
and the position of its first occurrence in the array. */

#include <stdio.h>

#define SIZE 100

int linear_search(double arr[], int size, double num, int *t);

int main(void)
{
    int i, times, pos;
    double num, arr[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number: ");
        scanf("%lf", &num);
        if(num == -1)
            break;
        arr[i] = num;
    }
    printf("Enter number to search: ");
    scanf("%lf", &num);

    pos = linear_search(arr, i, num, &times); /* The variable i indicates the number of the array's elements. */

    if(pos == -1)
        printf("%f isn't found\n", num);
    else
        printf("%f appears %d times (first pos = %d)\n", num, times, pos);
    return 0;

}

int linear_search(double arr[], int size, double num, int *t)
{
    int i, pos;

    pos = -1;

    *t = 0;

    for(i = 0; i < size; i++)
    {
        if(arr[i] == num)
        {
            (*t)++;
            if(pos == -1) /* Store the position of the first occurrence. */
                pos = i;

        }
    }
    return pos;
}