/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void){
    unsigned char i;

    for(i = 3; i && i-1; i--)
        printf("%d ", i);

    for(; ++i;)
        printf("\n%d ", i);
    return 0;
}