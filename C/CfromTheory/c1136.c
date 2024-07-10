/* What is the output of the following program? */

#include <stdio.h>

double *f(double ptr[]);

int main(void)
{
    int i;
    double a[8] = {0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8};

    printf("%.1f\n", *f(f(f(a))));
    for(i = 0; i < 8; i++)
        printf("a[%d] = %.1f\n", i, a[i]);
    return 0;
}

double *f(double ptr[])
{
    (*ptr)++;
    return ptr+2;
}

/* Answer: The f() calls are executed inside out. When f() is first called, we have ptr = a =
&a[0]. Therefore, the statement (*ptr)++; is equivalent to a[0]++; and a[0] becomes 1.1.
The return value a+2 is used as an argument in the second call, so f(f(a)) is translated
to f(a+2). Therefore, a[2] becomes 1.3. Similarly, the return value a+4 is used as an argu-
ment in the third call and a[4] becomes 1.5. Since the last call to f() returns the address
of a[6], the * operator is used to display its value, that is, 0.7. As a result, the content of a
is 1.1 0.2 1.3 0.4 1.5 0.6 0.7 0.8 */