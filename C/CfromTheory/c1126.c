/* What is the output of the following program? */

#include <stdio.h>

void test(int *ptr1, int *ptr2, int a);

int main(void)
{
    int i = 1, j = 2, k = 3;

    test(& i, &j, k);
    printf("%d %d %d\n", i, j, k);

    return 0;
}

void test(int *ptr1, int *ptr2, int a)
{
    ptr1 = ptr2;

    *ptr1 = 100;
    *ptr2 = 200;

    a = *ptr1 + *ptr2;
    printf("%d\n", a);
}

/* Answer: When test() is called, we have ptr1 = &i, ptr2 = &j and a = k. The statement
ptr1 = ptr2; makes ptr1 point to the address of j. Therefore, the statement *ptr1 = 100;
makes j equal to 100. Since ptr2 points to the address of j, the statement *ptr2 = 200;
changes the value of j to 200. Since the statement a = *ptr1 + *ptr2; is equivalent to a =
j+j = 200+200 = 400, test() displays 400. Since any change in the value of a does not
affect k, k remains the same. As a result, the program displays:
400
1 200 3 */