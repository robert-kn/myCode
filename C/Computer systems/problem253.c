#include <stdio.h>

/**
 * 1e400 overflows to infinity since the largest finite number that can be represented with double precision
 * is around 1.8 x 10^(308)
 * 
 * what is 1e400 in scientific notation?
 * */ 

#define POS_INFINITY 1e400
#define NEG_INFINITY (- POS_INFINITY)
#define NEG_ZERO (-1.0/POS_INFINITY)

int main(){
    printf("pos infinity = %lf\n neg infinity = %lf\n neg zero = %lf\n", POS_INFINITY, NEG_INFINITY, NEG_ZERO);
}
