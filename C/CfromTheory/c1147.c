#include <stdio.h>

int unknown(int arr[], int num);

int main(void)
{
    int arr[] = {10, 20, 30, 40};

    printf("%d\n", unknown(arr, 4));
    return 0;
}

int unknown(int arr[], int num)
{
    if(num == 1)
        return arr[0];
    else    
        return arr[num-1] + unknown(arr, num-1);
}

/* Answer: When unknown() is called, it returns
arr[4-1 = 3] + unknown(arr, 4-1 = 3) =
arr[3] + (arr[3-1] + unknown(arr, 3-1)) =
arr[3] + arr[2] + (arr[2-1] + unknown(arr, 2-1)) =
arr[3] + arr[2] + arr[1] + unknown(arr, 1)

The last call of unknown(arr, 1) returns arr[0], because num = 1. Therefore, the
return value is arr[3]+arr[2]+arr[1]+arr[0] and the program outputs 100. As a result,
the function calculates recursively the sum of the array’s elements.*/