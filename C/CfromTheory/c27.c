#include <stdio.h>
/**
 * Write a program that declares two floating-point variables (e.g., i, j), assigns to them two positive 
 * values 
 * (e.g., 3.45 and 6.78) and swaps their integer parts (that is, i becomes 6.45 and j becomes 3.78, 
 * respectively).
*/
int main(void){
    float f1 = 3.45, f2 = 6.78, temp = f1;

    float f1_fractional = f1 - (int) f1;
    float f2_fractional = f2 - (int) f2;
    
    f1 = f1_fractional + (float) ((int) f2);
    
    f2 = f2_fractional + (float) ((int) temp);
    printf("f1 = %.2f and f2 = %.2f\n", f1, f2);
    return 0;
}