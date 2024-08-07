/*What is the output of the following program? */

#include <stdio.h>

#define hide(t, r, a, p, i, n) p##a##r##t(i, n)

double show(int a, int b);

int main(void)
{
    printf("%d\n", (int)hide(w, o, h, s, 1, 2));
    return 0;
}
double show(int a, int b)
{
    return (a+b)/2.0;
}

/* The preprocessor replaces one by one the arguments of the hide() macro.
Therefore, the preprocessor substitutes t with w, r with o, and so on. Since the p, a, r, t are
replaced by the s, h, o, w and the ## operator merges the operands together, the macro is
expanded to show(i, n). Therefore, the program calls show() with arguments 1 and 2,
which returns their average, that is, 1.5. Since the return value casts to int, the program
displays 1.*/