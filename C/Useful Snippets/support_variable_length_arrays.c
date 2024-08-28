#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#if defined __STDC_NO_VLA__
    printf("Variable length arrays are not supported.\n");
    exit(EXIT_FAILURE);
#else   
    printf("They are supported\n");
#endif
}