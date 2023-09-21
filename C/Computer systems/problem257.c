// 
 
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
    short sval = (short) ival;
    char cval  = (char) ival;
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
	test_show_bytes(12345);
}