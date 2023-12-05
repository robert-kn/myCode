/*Our binary search makes two tests inside the loop, when one would suffice (at
the price of more tests outside.) Write a version with only one test inside the loop and
measure the difference in run-time.*/

#include <stdio.h>

#define ARRAYSIZE 400000000UL

int binsearch(unsigned long int x, unsigned long int v[], unsigned long int n){
    int low, mid, high;

    low = 0;
    high = n - 1;

    while(low < high){
        mid = (low + high)/2;
        if(x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }

    return (x == v[low])? low: -1;
}

int main(){
    unsigned long arr[ARRAYSIZE];
    unsigned long int i = 0;
    for(;i < ARRAYSIZE;i++)
        arr[i] = i;
    printf("%d\n", binsearch(ARRAYSIZE - 1, arr,ARRAYSIZE));
    return 0;
}