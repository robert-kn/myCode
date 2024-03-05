/**
 * What is the output of the following program?
*/

#include <stdio.h> 

int main(void)
{
    unsigned char i;
    for(i = 1; i <= 256; i*=4) 
        printf("One\n");
    return 0; 
}