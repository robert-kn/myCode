 #include <stdio.h>

 #define SHIFT 4

 int switch_off(int x);

 int main(){
    printf("0x%x\n", switch_off(0x49217951)); /* should return 0x49217941 */
    printf("0x%x\n", switch_off(0x492179e1)); /* should return 0x492179e1 */
 }

 int switch_off(int x){
    /* test whether the 4 bit is switched on */
    return (x & ~(1 << SHIFT));
 }
