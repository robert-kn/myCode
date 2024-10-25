/**
 * concurrency is used to refer to a host problems that arise and must be addressed 
 * when working on many things at once in the same program. Concurrency problems 
 * arose first within the operating system itself; the os is juggling many  things
 * at once, first running one process, then another, and so forth. unfortunately, 
 * the problems of concurrency are no longer limited just to the os itself. Indeed,
 * modern multi-threaded programs exhibit the same problems.
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"

void * worker(void * arg);

volatile int counter = 0;
int loops;

int main(int argc, char * argv[]){
    if(argc != 2){
        fprintf(stderr, "usage: threads <value>\n");
        exit(1);
    }

    loops = atoi(argv[1]);
    pthread_t p1, p2;
    printf("Initial value: %d\n", counter);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);
    pthread_join(p1, NULL);
    pthread_join(p2, NULL);
    printf("Final value: %d\n", counter);
    return 0;
}

void * worker(void * arg){
    int i;
    for(i = 0; i < loops; i++){
        counter++;
    }
    return NULL;
}