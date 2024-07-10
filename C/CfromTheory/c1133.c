/* Write a void function that takes as parameters an array that contains the prices
of some products in a shop and their number and uses proper variables to return the low-
est, the highest, and the average of the prices. Write a program that reads the prices of less
than 100 products and stores them in an array. If the user enters -1, the insertion of prices
should terminate. The program should use the function to display the lowest, the highest,
and the average of the prices. */

#include <stdio.h>

void stat_arr(float arr[], int size, float *min, float *max, float *avg);

int main(void)
{
    int i;
    float min, max, avg, arr[100];

    for(i = 0; i < 100; i++)
    {
        printf("Enter price: ");
        scanf("%f", &arr[i]);
        if(arr[i] == -1)
            break;
    }
    if(i == 0) /* The variable i indicates how many prices were stored into the array. For example, if the user does not enter the value -1, i would be equal to 100. */
        return 0;

    stat_arr(arr, i, &min, &max, &avg);
    printf("Max=%.2f Min=%.2f Avg=%.2f\n", max, min, avg);
    return 0;

}

void stat_arr(float arr[], int size, float *min, float *max, float *avg)
{
    int i;
    float sum;

    sum = *min = *max = arr[0];
    for(i = 1; i < size; i++)
    {
        if(arr[i] > *max)
            *max = arr[i];
        if(arr[i] < *min)
            *min = arr[i];
       
        sum += arr[i];
    }
    *avg = sum/size; 
}