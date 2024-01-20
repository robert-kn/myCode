/**
 * Fix the errors in order to run the program and display the values of a, b, and c.
*/
#include <stdio.h> 

int main(void)
{
    int a = 10, b = a/2;  
    float c = 4.0;
    a = 5 + a;
    printf("%d %.2f %d\n", a, c, b);
    return 0; 
}