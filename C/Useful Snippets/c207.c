/* What is the output of the following program? */

#include <stdio.h>

void test(int **tmp);

int main(void)
{
    int *ptr, arr[] = {5, 10, 15};

    ptr = arr;
    test(&ptr);

    printf("%d ", *ptr); 
    return 0;
}

void test(int **tmp)
{
    int i;

    i = *(*tmp)++; 
    printf("%d ", i);

    i = ++(**tmp); 
    printf("%d ", i);
}

/* When test() is called, we have tmp = &ptr, so *tmp is equivalent to ptr. Therefore, the expression 
i = *(*tm p)++  is equivalent to i = *ptr++. This statement frst assigns to i the value of *ptr, that is, 
*ptr = *arr = arr[0] = 5, and then ptr is incre- mented to point to arr[1]. Therefore, the program displays 5.
Then, we have i = ++(**tmp) = ++(*ptr) = ++arr[1]. Now, arr[1] is frst incremented and becomes 11, then, that 
value is assigned to i. Therefore, the program displays 11. After the execution of test(), since ptr points to 
arr[1], the program displays 11. */