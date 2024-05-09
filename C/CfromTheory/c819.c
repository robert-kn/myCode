/**
 * What is the output of the following program
*/

#include <stdio.h>
int main(void){
    int i, *ptr1, *ptr2, arr[] = {10, 20, 30, 40, 50, 60, 70};

    ptr1 = &arr[2];
    ptr2 = &arr[4];

    for(i = ptr2 - ptr1; i < 5; i += 2)
        printf("%d ", ptr1[i]);
    return 0;
}