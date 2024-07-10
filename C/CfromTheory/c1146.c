#include <stdio.h>

int a = 4;

int main(void)
{
    if(a == 0)
        return 0;
    else
    {
        printf("%d ", a--);
        main();
    }
    return 0;
}

/* Answer: Notice that main() can be also called recursively. In each call, a is decremented
by 1. The program stops calling main() once a becomes 0. Therefore, the program dis-
plays: 4 3 2 1 */