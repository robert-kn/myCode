/* What would be the output of the following program when the macro ONE:
a. is defined?
b. it is not defined?
Explain why. */

#include <stdio.h>

#define ONE 1
#define myprintf(a) printf("x" #a " = %d\n", x##a)

int main(void)
{
#ifdef ONE
#define TWO ONE+ONE
#else
#define ONE 2
#define TWO (ONE+ONE)
#endif
    int x1 = 3*(ONE+ONE), x2 = 3*TWO;
    myprintf(1);
    myprintf(2);
    return 0;
}