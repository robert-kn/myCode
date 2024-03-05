/**
 * What is the output of the following program?
*/

#include <stdio.h> 

int main(void){

    int i = -2; 
    
    while(i-6){

        printf("One "); 
        i++; 
        while(!(i+1))
        {
            printf("Two ");
            i--;
        }
        i += 2; 
    }
    return 0; 
}

/**
 * 1st iter --> i = -2 hence One, then i = -1, then Two, then i = -2, then i = 0. Output on the console One Two
 * 2nd iter --> i = 0  hence One, then i = 1, then i = 3. Output on the console One Two One
 * 3rd iter --> i = 3 hence One, then i = 4, then i = 6. Output on the console One Two One One
 * 4 iter not executed because condition is 0
*/
