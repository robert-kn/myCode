#include <stdio.h>

int main(void){
    short s = 12;
    long l = 50000;
    long double ld = 12.3;
    printf("%hd\n", s);
    printf("%ld\n", l);
    printf("%Lf\n", ld);
    return 0;
}