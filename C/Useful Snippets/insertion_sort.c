#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10

void insertion_sort(int list[]);

int main(void)
{
    int numbers[MAX_NUMS];
    int index;

    printf("Enter %d numbers\n", MAX_NUMS);
    for(index = 0; index < MAX_NUMS; index++)
    {
        printf("input number %d: ", index);
        scanf("%d", &numbers[index]);   
    }

    insertion_sort(numbers);
    printf("\n The input set, in ascending order\n");
    for(index = 0; index < MAX_NUMS; index++)
        printf("%d\n", numbers[index]);

    return EXIT_SUCCESS;
}

void insertion_sort(int list[])
{
    int unsorted;
    int sorted;
    int unsorted_item;

    for(unsorted= 1; unsorted < MAX_NUMS; unsorted++)
    {
        unsorted_item = list[unsorted];

        for(sorted = unsorted - 1; (sorted >= 0) && (list[unsorted] > unsorted_item); sorted--)
            list[sorted + 1] = list[sorted];

        list[sorted + 1] = unsorted_item;
    }
}