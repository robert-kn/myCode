/**
 * Use the p1 and p2 pointers and complete the following program to read the codes of 100 products and store them into arr. The program 
 * should store a code in the array only if it is not already stored. If the user enters -1, the insertion of codes should terminate. 
 * The program should display the codes of the stored products, before it terminates. Use pointer arithmetic to process the array.
*/

#include <stdio.h>

#define SIZE 100

int main(void) {
    int *p1, *p2, arr[SIZE];

    p1 = arr;
    while(p1 < arr+SIZE){
        printf("Enter code_%d: ", p1-arr+1);
        scanf("%d", p1);
        if(*p1 == -1)
            break;

        for(p2 = arr; p2 < p1; p2++) /* Traverse the array to check if the input code is already stored. */
        {
            if(*p1 == *p2)
            {
                printf("Error: Code %d exists\n", *p1);
                break;
            }
        }
        /* If the code is not stored, increase the pointer. */
        if(p2 == p1) 
            p1++;
    }
    /* Display the codes. */
    for(p2 = arr; p2 < p1; p2++)
        printf("C: %d\n", *p2);
    return 0;
}