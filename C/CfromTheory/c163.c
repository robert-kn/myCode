
/* What is the output of the following program? */

#include "test.h"

int main(void)
{
    f();
#ifdef TEST
    f();
#endif
    f();
    return 0;
}

/* The preprocessor replaces the first occurrence of f() with printf() and then
cancels the definition of TEST. Since TEST is not defined, the preprocessor does not expand
the second f() and continues with the third one. Therefore, the program displays: One
One.*/