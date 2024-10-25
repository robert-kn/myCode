#include <stdio.h>

int switch_on_rightmost_0(int x);

int main(){
    printf("%.8x\n", switch_on_rightmost_0(0x49ffffff)); /* should return 0x4bffffff */
    printf("%.8x\n", switch_on_rightmost_0(0x492179ef)); /* should return 0x492179ff */
}

int switch_on_rightmost_0(int x){
    /* test whether the 4 bit is switched on */
    return (x | (x + 1)); 
}