#include <stdio.h> 

int main(void)
{
    int a = 10, b = a/2;  
    float c = 4.0;
    a = 5 + a;
    printf("%d %f %d\n", a, c, b);
    return 0; 
}