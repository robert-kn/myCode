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

/* Answer: As said, when two pointers that point to the same array are subtracted, the
result is the number of elements between them, not their distance in memory. Therefore,
although the address of arr[4] is eight places higher than the address of arr[2], the result
of ptr2-ptr1 is equal to the difference of their subscripts, that is, 4-2 = 2. Since ptr1
points to arr[2], ptr1[2] corresponds to arr[4] and ptr1[4] to arr[6]. Therefore, the
program outputs 50 and 70. */