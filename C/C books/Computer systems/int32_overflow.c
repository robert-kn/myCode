#include <stdio.h>
#include <stdint.h>

int main(){
    int num = 200*300*400*500;
    unsigned int num2 = 200*300*400*500;
    uint64_t num3 = 200*300*400*500;
    printf("%d %d %lu\n", num, num2, num3);
    return 0;
}