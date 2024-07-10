/* What is the output of the following program? */

#include <stdio.h>

int *test(int *ptr1, int *ptr2);

int main(void)
{
    int arr[] = {1, 2, 3, 4};

    *test(arr, arr+3) = 30;
    printf("%d %d %d %d\n", arr[0], arr[1], arr[2], arr[3]);
    return 0;
}

int *test(int *ptr1, int *ptr2)
{
    *(ptr1+1) = 10;
    *(ptr2-1) = 20;
    return ptr1+3;
}

/* Answer: When test() is called, we have ptr1 = arr, so the pointer ptr1+1 points to
arr[1]. Therefore, the statement *(ptr1+1) = 10; makes arr[1] equal to 10. Similarly,
we have ptr2 = arr+3, so ptr2 points to arr[3]. Therefore, the statement *(ptr2-1) =
20; makes arr[2] equal to 20. Since ptr1 points to arr, the expression ptr1+3 returns
a pointer to arr[3]. Therefore, arr[3] becomes 30. As a result, the program displays: 1
10 20 30 */