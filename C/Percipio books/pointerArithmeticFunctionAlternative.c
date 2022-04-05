#include <stdio.h>

void reset(int []);

void main(){
    system("clear");
    int array[3] = {1, 2, 3};

    reset(array);
}

void reset(int array[]){

    array[0] = 10;
    array[1] = 15;
    array[2] = 20;
    printf("\nfirst index: %d second index: %d third index: %d\n", array[0], array[1], array[2]);
}