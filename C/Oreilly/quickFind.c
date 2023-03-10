/** 
 * This program reads a sequence of pairs of non-negatiive integers less than N from stdio
 * (interpreting the pair p q to mean "connect object p to object q") and prints out pairs representing
 * objects that are not yet connected. It maintains an array id that has an entry for each object, with 
 * the property that id[p] and id[q] are equal if and only if p and q are connected.
*/

// this quick find algorithm executes at least MN instructions to solve a connectivity problem with N objects
// that involves M union operations

#include <stdio.h>

void FlushInput();

#define N 1000

int main (){
    int i, p, q, t, id[N];

    for(i = 0; i < N; i++){
        id[i] = i;
    }

    while (scanf("%d %d\n", &p, &q) == 2){

        if(id[p] == id[q]) // are the two objects connected? or in other words are the values both equal?
                continue;
        
        for(t = id[p], i = 0; i < N; i++) {

            if (id[i] == t){    // if current object in array id equals the object referenced by the first index that was input by user...
                id[i] = id[q]; // assign the object at the index specified by user's second argument to the current position 
            }

            printf("%d %d\n", p, q);

            FlushInput();

        }
    }
    return 0;
}

void FlushInput(){
    char c;
    while((c = getchar()) != '\n' && c != EOF)
        ;
}