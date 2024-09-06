/* Write a function that takes as parameter an array of integers and uses the insertion
sort algorithm to sort it in ascending order. Write a program that reads five integers, stores
them in an array, and uses the function to sort it. */

#include <stdio.h>

#define SIZE 5

void insert_sort(int arr[]);

int main(void)
{
    int i, a[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number: ");
        scanf("%d", (a + i)); /* or &a[i] */
    }
    insert_sort(a);
    printf("\n***** Sorted array *****\n");
    for(i = 0; i < SIZE; i++)
        printf("%d\n", a[i]);
    return 0;
}

void insert_sort(int arr[])
{
    int i, j, temp;

    for(i = 1; i < SIZE; i++)
    {
        temp = arr[i];
        j = i;
        while((j > 0) && (arr[j-1] > temp))
        {
            arr[j] = arr[j-1]; /* Shift this element one position to the right */
            j--;
        }
        arr[j] = temp;
    }
}

/* To sort the array in descending order, change the while statement to
while((j > 0) && (arr[j-1] < temp))
in order to shift one position to the right, the elements of the sorted subarray, which
are less than the examined element. */