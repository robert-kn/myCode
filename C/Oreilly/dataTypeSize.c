#include <stdio.h>

int main(){
    printf("Signed int = %lu\n", sizeof(signed int));
    printf("Unsigned int = %lu\n", sizeof(unsigned int));

    printf("Signed char = %lu\n", sizeof(signed char));
    printf("Unsigned char = %lu\n", sizeof(unsigned char));

    printf("Signed short = %lu\n", sizeof(signed short));
    printf("Unsigned short = %lu\n", sizeof(unsigned short));

    printf("Signed long = %lu\n", sizeof(signed long));
    printf("Unsigned long = %lu\n", sizeof(unsigned long));

    printf("Signed long long = %lu\n", sizeof(signed long long));
    printf("Unsigned long long = %lu\n", sizeof(unsigned long long));

    printf("Float = %lu\n", sizeof(float));

    printf("Double = %lu\n", sizeof(double));
    printf("Long double = %lu\n", sizeof(long double));
}
    