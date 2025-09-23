/**
 * Figure 2.4 Code to print the byte representation of program objects. This code uses casting to circumvent the 
 * type system. Similar functions are easily defined for other data types.
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    int i;
    for(i = 0; i < len; i++)
    /**
     * the reference start[i] indicates that we want to read the byte that is i positions beyond the 
     * location pointed to by start.
     */
        printf("%.2x", start[i]);
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void * x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void test_show_bytes(int val)
{
    int ival = val;
    float fval = (float) ival;
    int * pval = &ival;
    show_int(ival);
    show_float(fval);
    show_pointer(pval);
}

int main(){
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer) &val;
    show_bytes(valp, 1); /* A. */ 
    show_bytes(valp, 2); /* B. */ 
    show_bytes(valp, 3); /* C. */
    show_bytes((byte_pointer) "12345", 6); /* will display 31 32 33 34 35 00 */
    show_bytes((byte_pointer) "abcdef", 7); 
    test_show_bytes(12345);
    return EXIT_SUCCESS;
}