/**
 * What is the output of the following program? You are reminded that printf()
returns the number of the displayed characters.
*/

#include <stdio.h> 

int main(void){
    int i, sum;
    float j = 1.2345;
    sum = 0;

    for(i = 0; i < 3; i++)
        sum = sum + printf("%.2f\n", j);

    printf("Val = %d\n", sum);
    return 0; 
}
