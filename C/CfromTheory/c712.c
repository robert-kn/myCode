/**
 * What is the output of the following program?
*/

#include <stdio.h> 

int main(void){
    int i, a[] = {10, 20, 30, 40, 50}; 
    double b[] = {2.2, 1.94, 0.5, -1, -2};

    for(i = 0; a[i] = b[i]; i++) 
        printf("%d ", a[i]);
    return 0; 
}

/**
 * The condition a[i] = b[i]; is equivalent to (a[i] = b[i]) != 0; which means 
that the elements of b are copied to the respective elements of a as long as a[i] does not become 0. If it does, the loop terminates. 
Since the type of a is int, only the integer parts of the b elements will be stored into the respective a elements. Therefore, when 
the value 0.5 is copied, a[2] becomes 0 and the loop terminates. As a result, the program outputs 2 1
*/