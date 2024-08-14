/* What is the output of the following program? */

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

/* Answer: Since ptr1 points to the address of i and ptr2 points to the address of j, the
statement *ptr1 = *ptr2 is equivalent to i = j. Since i is declared as int, it becomes 1. As
said, the pointer variables allocate the same size (typically, it is 4 bytes), no matter where
they point to. Since ptr2 is a pointer to double, the program displays: 1 8 8 8 */