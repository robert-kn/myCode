/**
 * Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types.
*/
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    printf("\n");

    printf("char min on your system has a value of %d\n", CHAR_MIN);
    printf("char max on your system has a value of %d\n", CHAR_MAX);
    printf("char has the following width in your system %d\n", CHAR_BIT);
    printf("unsigned char can accomodate values up to %d\n", UCHAR_MAX);
    printf("\n\n\n");

    printf("short min on your system has a value of %d\n", SHRT_MIN);
    printf("short max on your system has a value of %d\n", SHRT_MAX);
    printf("short has the following width in your system %d\n", __SHRT_WIDTH__);
    printf("unsigned short can accomodate values up to %d\n", USHRT_MAX);
    printf("\n\n\n");

    printf("int min on your system has a value of %d\n", INT_MIN);
    printf("int max on your system has a value of %d\n", INT_MAX);
    printf("int has the following width in your system %d\n", __INT_WIDTH__);
    printf("unsigned int can accomodate values up to %u\n", UINT_MAX);
    printf("\n\n\n");

    printf("long min on your system has a value of %ld\n", LONG_MIN);
    printf("long max on your system has a value of %ld\n", LONG_MAX);
    printf("long has the following width in your system %d\n", __LONG_WIDTH__);
    printf("unsigned long can accomodate values up to %lu\n", ULONG_MAX);
    printf("\n\n\n");

    printf("minimum normalized positive floating point number that is representable in type float %f\n", FLT_MIN);
    printf("Maximum representable number in type float %f\n", FLT_MAX);
    printf("number of decimal digits of precision for the float data type %d\n", FLT_DIG);

    printf("minimum normalized positive floating point number that is representable in type double %f\n", DBL_MIN);
    printf("Maximum representable number in type double %f\n", DBL_MAX);
    printf("number of decimal digits of precision for the double data type %d\n", DBL_DIG);

    printf("minimum normalized positive floating point number that is representable in type long double %Lf\n", LDBL_MIN);
    printf("Maximum representable number in type long double %Lf\n", LDBL_MAX);
    printf("number of decimal digits of precision for the long double data type %d\n", LDBL_DIG);



}