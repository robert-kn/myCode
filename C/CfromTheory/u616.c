/**
 * What is the output of the following program? Explain why.
*/

#include <stdio.h> 

int main(void){
    int i, j, k = 100; 
    
    for(i = 0; i < 2; i++){
        printf("One ");
        for(j = 0; k; j++){
            printf("Two ");
            k -= 50;
        }
    }
    return 0;   
 }
