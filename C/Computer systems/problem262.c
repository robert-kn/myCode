/**
 * Write a function int_shifts_are_arithmetic() that yields 1 when run on a 
 * machine that uses arithmetic right shifts for int’s, and 0 otherwise. 
 * Your code should work on a machine with any word size. Test your code on several machines.
*/
#include <stdio.h>

int int_shifts_are_arithmetic(int x);

int main(){
    int x = -120; /* should return 1 */
    //x = 12; /* should return 0 because most significant bit is 0 hence zeros will be padded on the left when it is righ shifted */
    printf("%d\n", int_shifts_are_arithmetic(x));
    return 0;
}

int int_shifts_are_arithmetic(int x){
    int shift_value = sizeof(int) << 3;
    int x_shifted_lsb_masked = (x >> (shift_value - 1)) & 0xff;
    return (x_shifted_lsb_masked == 0xff);
}


