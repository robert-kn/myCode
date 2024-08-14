/**
 * Use the p pointer and a while loop, and complete the following program to display the 
 * integers from 1 to 10.
*/

#include <stdio.h>

int main(void){
    int *p, i;
    i = 1;
    p = &i;
    while(i <= 10){
        printf("%d\n", *p);
        (*p)++;
    }
    return 0;
}