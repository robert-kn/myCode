#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b){
    int k = * a;
    *a = *b;
    *b = k;
}

int main(int argc, char * * argv){
    int u;
    int t;
    u = 17;
    t = -96;
    printf("address for u is %p, address for t is %p\n", &u, &t);
    printf("before swap u = %d, t = %d\n", u, t);
    swap(&u, &t);
    printf("after swap: u = %d, t = %d\n", u, t);
    return EXIT_SUCCESS;
}