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