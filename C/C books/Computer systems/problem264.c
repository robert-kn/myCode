/**
 * Write code to implement the following function.
 * 
 * Your function should follow the bit-level integer coding rules (page 120), except that you may assume that data
 * type int has w = 32 bits.
*/

/* Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32. */
#include <stdio.h>

int any_odd_one(unsigned x);

int  main(){
    printf("%d\n", any_odd_one(0x41514455)); /* should return 0 */
    printf("%d\n", any_odd_one(0x81514455)); /* should return 1 */
}
int any_odd_one(unsigned x){
    return  !!(0xaaaaaaaa & x);
}