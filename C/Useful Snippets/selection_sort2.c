/* Write a function that takes as parameters an array of doubles and uses the selec-
tion sort algorithm to sort it in ascending order. Write a program that reads the grades of
10 students, stores them in an array, and uses the function to sort it. */

#include <stdio.h>

#define SIZE 10

void sel_sort(double arr[]);

int main(void)
{
    int i;

    double grd[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter grade of stud_%d: ", i+1);
        scanf("%lf", &grd[i]);
    }
    sel_sort(grd);

    printf("\n***** Sorted array *****\n");
    for(i = 0; i < SIZE; i++)
        printf("%.2f\n", grd[i]);
    return 0;
}

void sel_sort(double arr[])
{
    int i, j;
    double tmp;

    for(i = 0; i < SIZE-1; i++)
    {
        for(j = i+1; j < SIZE; j++)
        {
            if(arr[i] > arr[j])
            {
                /* Swap values. */
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

/* Comments: In each iteration of the inner loop, arr[i] is compared with the elements from
i+1 up to SIZE-1. If an element is less than arr[i], their values are swapped. Therefore, 
in each iteration of the outer loop, the smallest value of the elements from i up to SIZE-1
is stored at arr[i]. To sort the array in descending order, change the if statement to:
if(arr[i] < arr[j]) */