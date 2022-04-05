#include <stdio.h>

void swap(int *, int *);

void main(){
    int a = 5;
    int b = 10;

    int * pointerA = &a;
    int * pointerB = &b;

    swap(pointerA, pointerB);
    system("clear");
    printf("Memory address of a: %p Memory address of b\n: %p", pointerA, pointerB);
    printf("\n");
    printf("value at var a = %d and value at var b = %d\n", * pointerA, * pointerB);
}

void swap(int * pointerA, int * pointerB){
    int temp = * pointerA;
    * pointerA = * pointerB;
    * pointerB = temp;
}