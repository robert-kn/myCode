#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num1 = 6;
    int num2 = 9;
    int num3 = num1 | num2;
    printf("%d\n", num3);
#if defined __STDC_NO_VLA__
    printf("Variable length arrays are not supported.\n");
    exit(EXIT_FAILURE);
#else   
    printf("They are supported\n");
#endif
}