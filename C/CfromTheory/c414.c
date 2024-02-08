/**
 * What does the following program do?
*/

#include <stdio.h> 

int main(void){
    unsigned char ch = 3;
    ch = ((ch&1) << 7) | ((ch&2) << 5) | ((ch&4) << 3) | ((ch&8) << 1) | ((ch&16) >> 1) | ((ch&32) >> 3) | ((ch&64) >> 5) | ((ch&128) >> 7);
    printf("%d\n", ch);
    return 0; 
}