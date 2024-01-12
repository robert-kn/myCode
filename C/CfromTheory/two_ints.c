#include <stdio.h>
int main(void){
    int i = 50;
    int j = 20;
    printf("sum = %d, difference = %d, product = %d, division = %.1f, \
     remainder = %d\n", i+j, i-j, i*j, i/(float)j, i%j);
    return 0;
}