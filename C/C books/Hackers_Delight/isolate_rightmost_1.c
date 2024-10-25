#include <stdio.h>

 
int isolate_rightmost_1(int x);

int main(){
    printf("%.8x\n", isolate_rightmost_1(0x49000000)); /* should return 0x01000000 */
    printf("%.8x\n", isolate_rightmost_1(0x492179e8)); /* should return 0x00000008 */
}

int isolate_rightmost_1(int x){
    /* test whether the 4 bit is switched on */
    return (x & -x); /* -x can also be written as ~x + 1 */
}