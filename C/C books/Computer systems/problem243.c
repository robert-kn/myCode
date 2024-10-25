// Practice problem 2.43

// In the following code, we have omitted the definitions of constants M and N: 
 
#define M      /* Mystery number 1 */
#define N      /* Mystery number 2 */
int arith(int x, int y) {
    int result = 0;
    result = x*M + y/N; /* M and N are mystery numbers. */
    return result;
} 

// We compiled this code for particular values of M and N. The compiler optimized the multiplication and division using 
// the methods we have discussed. The following is a translation of the generated machine code back into C: 
/* Translation of assembly code for arith */
int optarith(int x, int y) {
    int t = x;
    x <<= 5;
    x -= t;
    if (y < 0) y += 7;
    y >>= 3;  /* Arithmetic shift */
    return x+y;
}
// What are the values of M and N? 

// We have found that people have difficulty with this exercise when working directly with assembly code. It becomes 
// more clear when put in the form shown in optarith. We can see that M is 31; x*M is computed as (x<<5)-x.  
// We can see that N is 8; a bias value of 7 is added when y is negative, and the right shift is by 3. 