/**
 * Fill in code for the following C functions. Function srl performs a logical right shift using an arithmetic right 
 * shift (given by value xsra), followed by other operations not including right shifts or division. Function sra 
 * performs an arithmetic right shift using a logical right shift (given by value xsrl), followed by other operations 
 * not including right shifts or division. You may use the computation 8*sizeof(int) to determine w, the number of 
 * bits in data type int. The shift amount k can range from 0 to w − 1.
*/

#include <stdio.h>
#include <limits.h>

unsigned srl(unsigned x, int k);
int sra(int x, int k);

int main(){
    printf("%x\n", sra(0x89123456, 2));
    return 0;
}

unsigned srl(unsigned x, int k) {
    /* Perform shift arithmetically */
    unsigned xsra = (int) x >> k;

    int w = sizeof(int) << 3;
    int mask = ~(-1 << (w - k));
    return xsra & mask;
}

int sra(int x, int k) {
    /* Perform shift logically */
    int xsrl = (unsigned) x >> k;

    int w = sizeof(int) << 3;
    int mask = UINT_MAX  << (w - k);
    return xsrl | mask;
}