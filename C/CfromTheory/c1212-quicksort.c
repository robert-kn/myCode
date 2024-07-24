/* Write a program that reads 10 integers and stores them in an array. The program should use qsort() to sort the 
array in ascending order. Then, the program should read an integer and use bsearch() to check if it is stored in the array. */

#include <stdio.h> 
#include <stdlib.h>

#define NUM 10

int compare(const void *elem1, const void *elem2);

int main(void)
{
    int *pos, i, arr[NUM];

    for(i = 0; i < NUM; i++)
    {
        printf("Enter number: ");
        scanf("%d", &arr[i]);
    }

    qsort(arr, NUM, sizeof(int), compare);

    printf("\nSorted array: ");
    for(i = 0; i < NUM; i++)
        printf("%d ", arr[i]);

    printf("\n\nEnter number to search: ");
    scanf("%d", &i);

    pos = (int*)bsearch(&i, arr, NUM, sizeof(int), compare);

    if(pos == NULL)
        printf("\n%d isn't found\n", i);
    else
        printf("\n%d is in position_%d\n", i, pos-arr+1);
    return 0;
    
}

int compare(const void *elem1, const void *elem2)
{
    return *(int*)elem1 - *(int*)elem2;
}

/* Notice that the name of compare() is used as a pointer to that function. According to the declarations of qsort() and bsearch(), the 
parameters of compare() must be declared asconst void*pointers.Sincewecompareintegers,wecasttheirtypestoint*.Then, the values that the 
two pointers point to are compared and compare() returns a value, according to the description of bsearch().

If the searched value is found, bsearch() returns a pointer to the respective element, otherwise NULL. We cast the return type from 
void* to int* to make it clear. The program uses pointer arithmetic to display its position, if found. To sort the array in descending
order, just reverse the comparison:

int compare(const void *elem1, const void *elem2) 
{
    return *(int*)elem2 - *(int*)elem1; // For descending order. 
}

*/
