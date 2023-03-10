#include <stdio.h>

int main(){
    char word[]= "London";
    printf("Size of char type in C: %lu\n", sizeof(char));
    printf("Size of int type in C: %lu\n", sizeof(int));
    printf("Size of float: %lu\n", sizeof(float));
    printf("Size of double: %lu\n", sizeof(double));
    printf("Size of short: %lu\n", sizeof(short));
    printf("Size of long: %lu\n", sizeof(long));
    printf("Size of word: %lu\n", sizeof(word));
}