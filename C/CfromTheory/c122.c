/* Write a function that takes as parameter an integer array and returns the maxi-
mum number of the same occurrences. For example, if the array is {1, 10, -3, 5, -3, 8},
the function should return 2 because -3 appears the most times, that is, 2. Write a pro-
gram that reads 10 integers, stores them in an array, and uses the function to display
the maximum number of the same occurrences. */

#include <stdio.h>

#define SIZE 10

int num_occurs(int arr[]);

int main(void)
{
    int i, arr[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }
    printf("\nMax occurrences is %d\n", num_occurs(arr));
    return 0;
}

int num_occurs(int arr[])
{
    int i, j, k, max_times;

    max_times = 1;
    for(i = 0; i < SIZE; i++)
    {
        k = 1; /* Each number appears once at least. */
        for(j = i+1; j < SIZE; j++) /* Compare arr[i] with the rest elements. */
        {
            if(arr[i] == arr[j])
                k++;
        }
        if(k > max_times)
            max_times = k;
    }
    return max_times;
}