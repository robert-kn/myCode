/* What is the output of the following program? */

#include <stdio.h>

void test(int **tmp, int i);

int main(void)
{
    int **tmp, *ptr, i, arr[] = {10, 20, 30};

    ptr = arr;
    tmp = &ptr;
    for(i = 0; i < 3; i++)
    {
        test(tmp, i);
        printf("%d ", arr[i]);
    }
    return 0;
}

void test(int **tmp, int i)
{
    *(*tmp + i) += 50;
}

/* tmp is declared as a pointer to a pointer to an integer. The statement tmp =
&ptr; makes tmp point to the address of ptr, which points to the address of the first ele-
ment of the array arr. Since *tmp is equal to ptr, we have *(*tmp+i) = *(ptr+i) =
*(arr+i) = arr[i]. Therefore, each call to test() increases the respective element of the
array arr by 50, and the program displays: 60 70 80.*/