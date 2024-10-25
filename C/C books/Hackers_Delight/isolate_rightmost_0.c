#include <stdio.h>

int isolate_rightmost_0(int x);

int main(){
    printf("%.8x\n", isolate_rightmost_0(0x49ffffff)); /* should return 0x02000000 */
    printf("%.8x\n", isolate_rightmost_0(0x492179ef)); /* should return 0x00000010 */
}

int isolate_rightmost_0(int x){
    /* test whether the 4 bit is switched on */
    return (~x & (x + 1)); 
}