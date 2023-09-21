#include <stdio.h>

 
int propagate_rightmost_1(int x);

int main(){
    printf("%.8x\n", propagate_rightmost_1(0x49000000)); /* should return 0x49ffffff */
    printf("%.8x\n", propagate_rightmost_1(0x492179e8)); /* should return 0x492179ef */
}

int propagate_rightmost_1(int x){
    /* test whether the 4 bit is switched on */
    return (x | (x - 1)); 
}