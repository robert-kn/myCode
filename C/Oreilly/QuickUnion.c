#include <stdio.h>

#define N 1000

/**
 * for M (unions) > N, the quick-union algorithm could take more than MN/2 instructions 
 * to solve a connectivity problem with M pairs of N objects
*/

int main(){
    int i, j, p, q, id[N];

    for(i = 0; i < N; i++){
        id[i] = i;
    } 

    while(scanf("%d %d", &p, &q) ==  2){

        for( i = p; i != id[i]; i = id[i])
            ;

        for (j = q; j != id[j]; j = id[j])
            ;

        if (i == j)
            continue;
        
        id[i] = j;

        printf("%d %d\n", p, q);
    }
}