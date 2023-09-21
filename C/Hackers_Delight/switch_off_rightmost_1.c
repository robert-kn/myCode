#include <stdio.h>

 
int switch_off_rightmost_1(int x);

int main(){
    printf("%x\n", switch_off_rightmost_1(0x49217957)); /* should return 0x49217956 */
    printf("%x\n", switch_off_rightmost_1(0x492179e8)); /* should return 0x492179e0 */
}

int switch_off_rightmost_1(int x){
    /* test whether the 4 bit is switched on */
    return (x & (x - 1)); 
}
