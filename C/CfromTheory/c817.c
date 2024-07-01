/**
 * What is the output of the following program?
*/

#include <stdio.h>
int main(void){
    int i = 10, *p = &i;

    p[0] = 50;
    printf("%d\n", i+p[0]);
    return 0;
}

/** Answer: Since p points to the address of i, we can index it as an array of a single element.
Therefore, the statement p[0] = 50; is equivalent to i = 50; and the program displays 100.
What would happen if we write p[1] = 50; instead of p[0] = 50;?
The statement p[1] = 50; attempts to change the value of an out-of-bound address, which
may cause a program crash. */