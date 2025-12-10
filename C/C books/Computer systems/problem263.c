/**
 * Fill in code for the following C functions. Function srl performs a logical right shift using an arithmetic right shift (given by value xsra), followed by other operations not including right shifts or division. Function sra performs an arithmetic right shift using a logical right shift (given by value xsrl), followed by other operations not including right shifts or division. You may use the computation 8*sizeof(int) to determine w, the number of bits in data type int. The shift amount k can range from 0 to w − 1.
*/

#include <stdio.h>
#include <limits.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);

int main(){
    printf("%X\n", srl(0x89123456U, 2));
    printf("%X\n", sra(0x89123456, 2));
    return 0;
}

// 

// unsigned srl(unsigned x, int k) {
//     /* Perform shift arithmetically */
//     unsigned xsra = (int) x >> k;             // arithmetic right shift (fills with sign bit)
//     int w = sizeof(int) << 3;                  // number of bits in an int
//     unsigned mask = (1U << (w - k)) - 1;     // lower (w - k) bits = 1
//     return xsra & mask;                     // clear sign bits
// }

// int sra(int x, int k) {
//     /* Perform shift logically */
//     int xsrl = (unsigned) x >> k;       // logical shift (fills with 0s)
//     int w = 8 * sizeof(int);            // number of bits in an int
//     int sign = x >> (w - 1);               // all 1s if x < 0, all 0s if +ve
//     int mask = ~((1 << (w - k)) - 1);      // top k bits = 1
//     mask &= sign;                          // keep only if negative
//     return xsrl | mask;

// }

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;             // arithmetic right shift (fills with sign bit)
    int w = 8 * sizeof(int);                  // number of bits in an int
    unsigned mask = (1U << (w - k)) - 1;     // lower (w - k) bits = 1
    return xsra & mask;                     // clear sign bits
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;       // logical shift (fills with 0s)
    printf("%x\n", xsrl);
    int w = 8 * sizeof(int);            // number of bits in an int
    int sign = x >> (w - 1);               // all 1s if x < 0, all 0s if +ve
    int mask = ~((1 << (w - k)) - 1);      // top k bits = 1
    mask &= sign;                          // keep only if negative
    return xsrl | mask;

}