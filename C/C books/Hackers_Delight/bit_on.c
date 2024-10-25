 #include <stdio.h>

 #define SHIFT 4
 
 int bit_set(int x);

 int main(){
    printf("%d\n", bit_set(0x49217951)); /* should return 1 */
    printf("%d\n", bit_set(0x492179e1)); /* should return 0 */
 }

 int bit_set(int x){
    /* test whether the 4 bit is switched on */
    return !!(x & (1 << SHIFT));
 }

