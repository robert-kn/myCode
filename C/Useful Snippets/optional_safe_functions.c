#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <string.h>

/* this code determines whether the standard library that comes with my C compiler supports safe functions ending
with _s. The book Beginning C claims that I must define the symbol __STDC_WANT_LIB_EXT1__ in my source file to 
represent the value 1 prior to including directive string.h

However when this code is run it still outputs optional functions are not defined. What am I missing? */
int main(void)
{
#if defined __STDC_LIB_EXT1__
    printf("Optional functions are defined.\n");
#else
    printf("Optional functions are not defined.\n");
#endif
    return 0;
}