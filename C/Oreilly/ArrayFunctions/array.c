#include <stdio.h>

void incr_arr(int * arr, int num)
{
    int i;
    for(i = 0; i < num; i++)
    {
        * (arr + i) = (*(arr + i) * 2);
    }

}

int main()
{
    int arr[5];
    arr[0] = 40;
    arr[1] = -7;
    arr[2] = 4;
    arr[3] = 45;
    arr[4] = 9;
    incr_arr(arr, 5);
    printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
    return 0;
}