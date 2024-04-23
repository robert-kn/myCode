/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void){
    int *p[3], i, num;

    for(i = 0; i < 3; i++)
    {
        printf("Enter number: ");
        scanf("%d", &num);
        p[i] = &num;
    }

    for(i = 0; i < 3; i++)
        printf("Num: %d\n", *p[i]);

    return 0;
}

/**
 * Answer: The statement p[i] = &num; makes each element of p to point to the address of num. Since all three pointers point to the same address, their content would be equal to the last value of num. 
 * Therefore, the second loop outputs three times the last input value.
 * 
*/