#include <stdio.h>

int main(void){
    float * f_ptr;
    int * i_ptr;
    char * c_ptr;
    printf("float type pointer has size %lu, int type pointer has size %lu, char type pointer has size %lu\n", sizeof(f_ptr), sizeof(i_ptr), sizeof(c_ptr));
    return 0;
}