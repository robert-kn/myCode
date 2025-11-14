/**
 * Fill in code for the following C functions. Function srl performs a logical right shift using an arithmetic right shift (given by value xsra), followed by other operations not including right shifts or division. Function sra performs an arithmetic right shift using a logical right shift (given by value xsrl), followed by other operations not including right shifts or division. You may use the computation 8*sizeof(int) to determine w, the number of bits in data type int. The shift amount k can range from 0 to w – 1.
 */

 #include <stdio.h>
 #include <stdlib.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    unsigned int i;
    for(i = 0; i < len; i++)
    {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

unsigned srl(unsigned x, int k) { 
    /* Perform shift arithmetically */ 
    unsigned xsra = (int) x >> k;  /* arithmetic right shift */
    show_bytes((byte_pointer) &xsra, sizeof(xsra));
    int w = 8 * sizeof(int);
    // int mask = (1U << (w - k)) - 1;     /* ~0U >> k is safer */
    int mask = ~0U >> k;
    return xsra & mask;
} 

int sra(int x, int k) { 
    /* Perform shift logically */ 
    int xsrl = (unsigned) x >> k; 
    show_bytes((byte_pointer) &xsrl, sizeof(xsrl));
    int w = 8 * sizeof(int);
    // int mask = ~((1 << (w - k)) - 1);
    int mask = ~(~0U >> k);
    int sign = x >> (w - 1);
    mask = mask & sign;
    return xsrl | mask;
}

int main(void)
{
    unsigned int x = 0x87654321;
    unsigned int answer = srl(0x87654321, 4);
    show_bytes((byte_pointer) &answer, sizeof(answer));
    int y = 0x87654321;
    int answer_2 = sra(y, 4);
    show_bytes((byte_pointer) &answer_2, sizeof(answer_2));
    exit(EXIT_SUCCESS);
}