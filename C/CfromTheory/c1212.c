/* quick sort algorithm */

#include <stdio.h>

#define SIZE 7

int partition(int a[], int l, int r);
void quick_sort(int a[], int l, int r);

int main(void)
{
    int i, a[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number: ");
        scanf("%d", &a[i]);
    }
    quick_sort(a, 0, SIZE-1);

    printf("\n***** Sorted array *****\n");
    for(i = 0; i < SIZE; i++)
        printf("%d\n", a[i]);
    return 0;
}

void quick_sort(int a[], int l, int r)
{
    int i;

    if(r <= l)
        return;
    i = partition(a, l, r);
    quick_sort(a, l, i-1);
    quick_sort(a, i+1, r);
}

int partition(int a[], int l, int r)
{
    int i, j, v, tmp;

    i = l;
    j = r-1;
    v = a[r];

    while(1)
    {
        while(a[i] < v)
            i++;
        while(a[j] >= v)
        {
            j--;
            if(j == 1) /* We check the case that the partition element is the lower in the examined part. */
                break;
        }
        if(i >= j)
            break;
        
        tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }

    tmp = a[i];
    a[i] = a[r];
    a[r] = tmp;
    return i;
}

/* Comments: Suppose that the user enters the values 2, 15, 4, 1, 7, 20, 5. Let’s trace
the first call of partition(). We have i=l=0, j=r-1=5, v=a[6]=5. The first loop performs
the left scan and terminates once i becomes 1 (since a[1] > 5). The second loop per-
forms the right scan and terminates once j becomes 3 (since a[3] < 5). The two elements
are swapped and the array is transformed to 2, 1, 4, 15, 7, 20, 5.

Left scan continues and terminates once i becomes 3 (since a[3] > 5). Right scan con-
tinues and terminates once j becomes 2 (since a[2] < 5). Because i > j the infinite loop
terminates. a[3] and a[6] are swapped and the array is transformed to 2, 1, 4, 5, 7, 20,
15. Notice that 5 is set in its final position and all elements in its left are less, while all ele-
ments in its right are greater. The function returns the value of i, that is, 3. Then, recursion
is used to repeat the same procedure for the left subarray (positions 0 to 2) and for the right
subarray (positions 4 to 6).*/