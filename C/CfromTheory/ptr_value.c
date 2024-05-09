#include <stdio.h>

int main(void){
    float * f_ptr;
    printf("Addr = %p\n", f_ptr);
    f_ptr = NULL;
    printf("Addr = %p\n", f_ptr);
    return 0;
}