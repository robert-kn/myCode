/**
 * Write a procedure is_little_endian that will return 1 when compiled and run on a little-endian machine, and will 
 * return 0 when compiled and run on a big- endian machine. This program should run on any machine, regardless of its 
 * word size.
*/
#include <stdio.h>
typedef unsigned char * byte_pointer;

int show_bytes(byte_pointer, unsigned int);

int main(){
    unsigned int x = 0x87654321;
    
    byte_pointer start = (byte_pointer) &x;

    printf("%d\n", show_bytes(start, 0x21));
}

int show_bytes(byte_pointer start, unsigned int lsb0){
    unsigned int lsb = start[0];
    if(lsb == lsb0) 
        return 1; 
    return 0;
}