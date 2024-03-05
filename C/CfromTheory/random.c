#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int i, num;

    srand(time(NULL));
    for(i = 0; i < 5; i++){
        num = rand();
        printf("%d\n", num);
    }

    return 0;
}