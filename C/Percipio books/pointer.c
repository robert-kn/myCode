#include <stdio.h>

void main(){
    int i = 4;
    char c = '?';
    double d = 5.2;
    short s = 23;

    int * pointerInt = &i;
    char * pointerChar = &c;
    double * pointerDouble = &d;
    short * pointerShort = &s;

    system("clear");

    /* How to print out the memory address of a variable */
    printf("Memory address of int is %p\n", pointerInt);
    printf("Memory address of char is %p\n", pointerChar);
    printf("Memory address of double is %p\n", pointerDouble);
    printf("Memory address of short is %p\n", pointerShort);

    printf("\n");
    printf("\n");

    /* How to dereference a pointer to print out the data stored in the referenced variable */
    printf("The data stored in the referenced int variable is %d\n", * pointerInt);
    printf("The data stored in the referenced char variable is %c\n", * pointerChar);
    printf("The data stored in the referenced double variable is %lf\n", * pointerDouble);
    printf("The data stored in the referenced short variable is %d\n", * pointerShort);

}