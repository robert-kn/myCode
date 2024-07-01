/**
 * What is the output of the following program?
 */

#include <stdio.h>

int main(void)
{
    int i = 100;

    i = i+i;
    printf("V1:%d V2:%d\n", i+i, i);
    return 0;
}

/**
 * Answer: The statement i = i+i; makes the value of i equal to i = i+i = 100+100 =
200. The first %d is replaced by the value 200+200 = 400, while the second %d by the value
of i, that is, 200. Therefore, the program displays: V1:400 V2:200.
 */