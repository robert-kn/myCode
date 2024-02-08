/**
 * Write a program that reads an integer in [0, 255], then it swaps the two quads of its binary digits and displays 
 * the new number. For example, if the user enters 10 (000010102), the program should display 160 (101000002).
*/

#include <stdio.h>

int main (void){
    unsigned char num, first_quad, second_quad, copy;

    printf("Enter number between [0-255]: ");
    scanf("%d", &num);
    copy = num;

    first_quad = (num & 0xf) << 4;
    second_quad = (num & 0xf0) >> 4;
    num = first_quad | second_quad;
    printf("original num %#x; reversed num %#x\n", copy, num);
    //printf("original num %d; reversed num %d\n", copy, num);
    return 0;
}

/**
 * alternatively, you could read the number into a variable as above then assign the rightmost quad into 
 * a temp var as such 
 * 
 * temp = num & 0xf; --> cleave of the rightmost quad
 * 
 * temp <<= 4; ---> shift all of the bits to the left; the rightmost quad will now be in the leftmost quad position
 * 
 * you can then populate the rightmost quad with the bits from the leftmost quad 
 * temp += (num >> 4);
 * 
*/