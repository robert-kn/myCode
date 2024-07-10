/* What is the output of the following program? */

#include <stdio.h>

float *test(float *ptr1, float *ptr2);

int main(void)
{
    float a = 1.2, b = 3.4;

    *test(&a, &b) = 5.6;
    printf("val1 = %.1f val2 = %.1f\n", a, b);

    *test(&a, &b) = 7.8;
    printf("val1 = %.1f val2 = %.1f\n", a, b);
    return 0;
}

float *test(float *ptr1, float *ptr2)
{
    if(*ptr1 < *ptr2)
        return ptr1;
    else
        return ptr2;
}

/* Answer: test() returns a pointer to the parameter with the smaller value. In the first call,
we have ptr1 = &a, so *ptr1 = a = 1.2. Similarly, we have ptr2 = &b, so *ptr2 = b =
3.4. Therefore, test() returns the ptr1 pointer. Since test() returns a pointer to a, the
statement *test(&a, &b) = 5.6; makes a equal to 5.6. Therefore, the program displays
val1 = 5.6 val2 = 3.4.
The second call of test() returns the ptr2 pointer because *ptr1 = a = 5.6 and
*ptr2 = b = 3.4. Like before, since test() returns a pointer to b, b becomes 7.8 and the
program displays: val1 = 5.6 val2 = 7.8 */