#include <stdio.h>

 #define SHIFT 4
 
 int flip_bit(int x);

 int main(){
    printf("%x\n", flip_bit(0x49217951)); /* should return 49217941 */
    printf("%x\n", flip_bit(0x492179e1)); /* should return 492179f1 */
 }

 int flip_bit(int x){
    /* test whether the 4 bit is switched on */
    return (x ^ (1 << SHIFT));
 }
