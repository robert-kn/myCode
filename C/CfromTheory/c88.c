#include <stdio.h>

int main(void){
    int *ptr1, i = 10;
    double *ptr2, j = 1.234;

    ptr1 = &i;
    ptr2 = &j;

    *ptr1 = *ptr2;
    printf("%d %lu %lu %lu\n", i, sizeof(ptr1), sizeof(ptr2), sizeof(*ptr2));
    return 0;
}