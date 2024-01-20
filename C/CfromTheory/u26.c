/**
 * Fill in the gaps and complete the program in order to display the following output.
*/

// 21 
//  21
// 15 
// 25% 
// A
//  a
// 10
// 77
// 077
// 63

#include <stdio.h> 

int main(void)
{
    int x = 21, y = 0xa, z = 077;
    printf("%d\n", x);
    printf("% d\n", x);
    printf("%d\n", x-6);
    printf("%d%%\n", x+4);
    printf("%X\n", y);
    printf("%2x\n", y);
    printf("%d\n", y);
    printf("%d\n", z+y+4);
    printf("%#o\n", z);
    printf("%d\n", z); 
    return 0;

}

         