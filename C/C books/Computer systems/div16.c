#include <stdio.h>

int div16(int);

int main(){
    printf("96/16 = %d\n", div16(96));
}

int div16(int x){
    return (x + (1 << 4) - 1) >> 4;
}