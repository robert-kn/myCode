/* What is the output of the following program? */

#include <stdio.h>

int *test(int p[], int *ptr2);

int main(void)
{
    int *ptr, i = 1, arr[] = {10, 20, 30, 40, 50, 60, 70};

    ptr = test(arr+2, &i);
    printf("%d %d\n", arr[4], *ptr);
    return 0;
}

int *test(int p[], int *ptr2)
{
    p[2] = 200;
    return p+*ptr2;
}

/* Answer: When test() is called, we have p = arr+2 = &arr[2] and ptr2 = &i. Therefore,
p[0] is equal to arr[2], p[1] equals arr[3], and p[2] equals arr[4]. Therefore, with the
statement p[2] = 200; the value of arr[4] becomes 200. Since ptr2 points to the address
of i, the expression p+*ptr2; is equivalent to p+i = p+1. Since p points to the third ele-
ment of the array arr, test() returns a pointer to its fourth element. Since that pointer is
stored into ptr, *ptr becomes equal to arr[3]. As a result, the program displays: 200 40 */