/**
 * Applications that get data from the hardware often need to retrieve the values of certain bits. For example, 
 * write a program that reads an integer and a bit position and displays the value of the respective bit. 
 * Assume that the user enters a bit position within [1, 32].
*/

#include <stdio.h>
#include <limits.h>

int main(void){
    int num, bit_pos;

    printf("Enter number between %d and %d: ", INT_MIN, INT_MAX);
    scanf("%d", &num);

    printf("Enter bit position desired [1, 32]: ");
    scanf("%d", &bit_pos);

    printf("The bit at position %d is %d\n", bit_pos, (num >> (bit_pos - 1) & 1));
    return 0;
}