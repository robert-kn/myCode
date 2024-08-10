/* What is the output of the following program? */

#include <stdio.h>

void test(int val, int *tmp);

int main(void)
{
    int *ptr, i, arr[] = {5, 10, 15};

    ptr = arr;
    for(i = 0; i < 2; i++)
    {
        test(*ptr, ptr);
        ptr++;
    }
    while(ptr >= arr)
    {
        printf("%d ", *ptr);
        ptr--;
    }
    return 0;
}

void test(int val, int *tmp)
{
    printf("%d %d\n", ++val, (*tmp)++);
}

/* First iteration of the for loop: When test() is called, we have val = *ptr = *arr = arr[0] = 5. The expression ++val frst increments val by one, and the program displays 6. Also, we have tmp = ptr = arr. Therefore, the expression (*tmp)++ is equivalent to (*arr)++ = arr[0]++. Now, the program frst displays the value of arr[0], that is, 5, and 
then it is incremented by one.
Second iteration of the for loop: ptr has been increased, so it points to the second element. When test() is called, we have val = *ptr = *(a r r+1) = arr[1] = 10. The expression ++val increments val and the program displays 11. Also, we have tmp = ptr = arr+1 = &arr[1]. Therefore, the expression (*tmp)++ is equivalent to arr[1]++. The program frst displays the value of arr[1], that is, 10, and then it is incremented by one.
Execution of the while loop: ptr has been increased, so it points to the third element. Therefore, the frst iteration displays the value of arr[2], that is, 15, and ptr is decre- mented and points to arr[1]. Therefore, the second iteration displays the value of arr[1], that is, 11, and the last one the value of arr[0], that is, 6.

To sum up, the program displays:

6    5 
11  10 
15  11  6*/