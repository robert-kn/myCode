/**
 * Write a program that reads integers continuously and displays them until the user enters 0. The number 0 must not be displayed.
*/

#include <stdio.h>

int main(void){
    int num;

    printf("Enter num: ");
    scanf("%d", &num);

    while(num){ /* this is the same as stating num != 0 */
        printf("Number entered was %d\n", num);
        printf("Enter num: ");
        scanf("%d", &num);
    }
    return 0;
}