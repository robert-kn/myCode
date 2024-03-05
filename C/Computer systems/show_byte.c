#include <stdio.h>
#include <string.h>

typedef unsigned char * byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    int i;
    for(i = 0; i  < len; i++)
        printf("%.2x", start[i]);
    printf("\n");
}

void show_char(char x){
    show_bytes((byte_pointer) &x, sizeof(char));
}

void show_short(short x){
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_long(long x){
    show_bytes((byte_pointer) &x, sizeof(long int));
}

void show_longL(long long x){
    show_bytes((byte_pointer) &x, sizeof(long long int));
}

void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_pointer(void * x){
    show_bytes((byte_pointer) &x, sizeof(void *));
}

void show_double(double x){
    show_bytes((byte_pointer) &x, sizeof(double));
}





void test_show_bytes(int val){
    int ival = val;
    char cval  = (char) ival;
    short sval = (short) ival;
    long  lval = (long) ival;
    long  long llval = (long long) ival;
    float fval = (float) ival;
    int * pval = &ival;
    double dval = (double) ival;
    
    show_char(cval);
    show_short(sval);
    show_int(ival);
    show_long(lval);
    show_longL(llval);
    show_float(fval);
    show_pointer(pval);
    show_double(dval);
}

int main(){
    show_bytes("abcdef", 6);
    // test_show_bytes(12345);
    //int a = 0x12345678;
    //byte_pointer ap = (byte_pointer) &a;
    //show_bytes(ap, 1);  /* A. */
    //show_bytes(ap, 2);  /* B. */
    //show_bytes(ap, 3);  /* C. */
    //show_bytes(ap, 4);
    //const char * m = "abcdef";
    //show_bytes((byte_pointer) m, strlen(m));
    //return 0;
    //short x  = 12345;
    //short mx = -x;
    //show_bytes((byte_pointer) &x,  sizeof(short));
    //show_bytes((byte_pointer) &mx, sizeof(short));
    //short sx = -12345;
    //unsigned short usx = sx;
    //int x = sx;
    //unsigned  ux = usx;

    //printf("sx = %d:\t", sx);
    //show_bytes((byte_pointer) &sx, sizeof(short));
    //printf("usx = %u:\t", usx);
    //show_bytes((byte_pointer) &usx, sizeof(unsigned short));
    //printf("x = %d:\t", x);
    //show_bytes((byte_pointer) &x, sizeof(int));
    //printf("ux = %u:\t", ux);
    //show_bytes((byte_pointer) &ux, sizeof(unsigned));
}