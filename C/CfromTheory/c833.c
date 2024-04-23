/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void){
    int *p, **pp, i = 10, j = 20;
    p = &i; 
    pp = &p;

    **pp += 100;
    p = &j;
    **pp += 100;
    printf("%d\n", i+j);
    return 0;
}

/**
 * Answer: Since pp points to p and p points to i, **pp is equal to i. Therefore, the statement **pp += 100; is equivalent to i = i+100 = 10+100 = 110. The statement p = &j, makes p point to j, so **pp is equal to j. Therefore, the 
 * statement **pp += 100; is equivalent to j = j+100 = 20+100 = 120. As a result, the program displays 230.
*/