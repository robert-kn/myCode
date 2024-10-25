/**
** In several of the following problems, we will artificially restrict what programming constructs you can use 
** to help you gain a better understanding of the bit-level, logic, and arithmetic operations of C. In answering 
** these problems, your code must follow these rules:
*
*    . Assumptions
*
*    Integers are represented in two’s-complement form.
*    Right shifts of signed data are performed arithmetically.
*    Data type int is w bits long. For some of the problems, you will be given a specific value for w, but otherwise
*    your code should work as long as w is a multiple of 8. You can use the expression sizeof(int)<<3 to compute w.
*
*    . Forbidden
*
*    Conditionals (if or ?:), loops, switch statements, function calls, and macro invocations.
*    Division, modulus, and multiplication.
*    Relative comparison operators (<, >, <=, and >=).
*    Casting, either explicit or implicit.
*
*    . Allowed operations
*
*    All bit-level and logic operations.
*    Left and right shifts, but only with shift amounts between 0 and w − 1. 
*    Addition and subtraction.
*    Equality (==) and inequality (!=) tests. (Some of the problems do not allow these.)
*    Integer constants INT_MIN and INT_MAX.
*
*    Even with these rules, you should try to make your code readable by choosing descriptive variable names and 
*    using comments to describe the logic behind your solutions. As an example, the following code extracts the most 
*    significant byte from integer argument x:
*
*   int get_msb(int x) {
        // Shift by w-8
        int shift_val = (sizeof(int)-1)<<3;
        // Arithmetic shift
        int xright = x >> shift_val;
        // Zero all but LSB
        int xright = x >> shift_val;
*/

/**
 * Write C expressions that evaluate to 1 when the following conditions are true, and to 0 when they are false. 
 * Assume x is of type int.
 * 
 * A. Any bit of x equals 1.
 * B. Any bit of x equals 0.
 * C. Any bit in the least significant byte of x equals 1.
 * D. Any bit in the most significant byte of x equals 0.
 * 
 * Your code should follow the bit-level integer coding rules (page 120), with the additional restriction that 
 * you may not use equality (==) or inequality (!=) tests.
*/

#include <stdio.h>

int any_bit1(int x){
    /**
     * if any bit in x is non zero the inner not operation will yield 0x00 which will  
     * be converted to 0x01 by the outer operation which is the correct answer.
     * 
     * if any bit in x is zero the inner not operation will yield 0x01 which 
     * will be converted to 0x00 by the outer operation which is the correct answer.
    */
    return !(!x);
}

int any_bit0(int x){
    /**
     * the bit pattern will first be complemented then:
     *  1. if the number is greater than 0, 0x00 will be returned by the inner not operation 
     *     which will then be converted to 0x01 by the outer not operation
     *  2. if the number is 0, 0x01  will be returned by the inner  not operation
     *     which will then be converted to 0x00  by the outer not operation   
    */
   return !(!(~x));
}

int lsb_any_bit1(int x){
    return !(!(0xff & x));
}

int msb_any_bit0(int x){
    int shift_val = (sizeof(int) - 1)  << 3;
    int shifted_x = (~x) >> shift_val;
    return !!(shifted_x & 0xff);
}

int main(){
    //printf("%d\n", any_bit1(0x12345678)); /* should return 1 */
    //printf("%d\n", any_bit1(0x00000000)); /* should return 0 */
    //printf("%d\n", any_bit0(0x12345678)); /* should return 1 */
    //printf("%d\n", any_bit0(0xffffffff)); /* should return 0 */
    //printf("%d\n", lsb_any_bit1(0x12345678)); /* should return 1 */
    //printf("%d\n", lsb_any_bit1(0x12345600)); /* should return 0 */
    //printf("%d\n", msb_any_bit0(0x12345600)); /* should return 1 */
    //printf("%d\n", msb_any_bit0(0xff345678)); /* should return 0 */
}