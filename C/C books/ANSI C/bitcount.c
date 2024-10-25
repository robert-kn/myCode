#include <stdio.h>

/* the function bitcount counts the number of 1-bits in its integer argument. */

int bitcount(unsigned x){
    int b;

    for(b = 0; x != 0; x >>= 1)
        if(x & 01)
            b++;
    return b;
}

int main(){
    unsigned int num = 0x777;
    printf("Number of 1  bits in the argument is %d\n", bitcount(num));
}