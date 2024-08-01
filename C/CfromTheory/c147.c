/* Write a function that takes as parameters two arrays of doubles (e.g., a1 and a2) of the same size and their number of elements and allocates memory to store the elements of a1 that are not 
contained in a2. The function should return a pointer to that memory. Write a program that reads pairs of doubles and stores them into two arrays of 100 ele- ments (e.g., p1 and p2). If either 
input value is –1, the insertion of numbers should end. The program should use the function to display the elements of p1 that are not contained in p2.*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

double *find_diff(double a1[], double a2[], int size, int *items); /* items indicates how many elements are stored in the memory. A pointer is passed, so that the function may change its value. */

int main(void)
{
    int i, elems;
    double *p3, j, k, p1[SIZE], p2[SIZE];

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter numbers: ");
        scanf("%lf%lf", &j, &k);
        if((j == -1) || (k == -1))
            break;
        p1[i] = j;
        p2[i] = k;
    }
    elems = 0;
    p3 = find_diff(p1, p2, i, &elems);
    if(elems == 0)
        printf("\n***** No different elements *****\n");
    else
    {
        for(i = 0; i < elems; i++)
            printf("%f\n", p3[i]);
    }
    free(p3);  
    return 0;
}

double *find_diff(double a1[], double a2[], int size,int *items)
{
    int i, j, found;
    double *mem;

    mem = (double*) malloc(size * sizeof(double)); 
    if(mem == NULL)
    {
        printf("Error: Not available memory\n"); 
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < size; i++)
    {
        found = 0; /* This variable indicates whether an element of the first array exists in the second, or not. The value 0 means that it does not exist. */

        for(j = 0; j < size; j++)
        {
            if(a2[j] == a1[i])
            {
                found = 1;
                break; /* Since this element exists, we stop searching. */
            }
        }
        /* If it does not exist, it is stored in the memory. */
        if(found == 0)
        {
            mem[*items] = a1[i]; 
            (*items)++;
        }
    }
    return mem;
}