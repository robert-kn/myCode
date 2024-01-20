/**
 * Use the flags of printf() to fill in the gaps and complete the program in order to
display the following output
*/

/**
 * x + yj = 2−3j
   x − yj = 2+3j
   y + xj = −3+2j
   y − xj = −3−2j
 * 
 * 
*/



#include <stdio.h> 
int main(void)
{
    int x = 2, y = -3;
    printf("x + yj = %d%dj\n", x, y); 
    printf("x − yj = %d%+dj\n", x, -y); 
    printf("y + xj = %d%+dj\n", y, x); 
    printf("y − xj = %d%dj\n", y, -x); 
    return 0;
}