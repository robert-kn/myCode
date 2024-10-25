 #include <stdio.h>

 #define SHIFT 4

 int switch_on(int x);

 int main(){
    printf("0x%x\n", switch_on(0x49217951)); /* should return 0x49217951 */
    printf("0x%x\n", switch_on(0x492179e1)); /* should return 0x492179f1 */
 }

 int switch_on(int x){
    /* test whether the 4 bit is switched on */
    return (x | (1 << SHIFT));
 }
