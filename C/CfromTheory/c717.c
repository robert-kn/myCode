/***
 * Write a program that reads an integer and displays it in binary. Use an array to store the bits of the number. To display the bits of a 
 * negative number, use the two’s complement technique. For example, if the user enters -5:
*/

#include <stdio.h> 

int main(void){
    int i, j, tmp, bits[32]; /* This array holds the bits of the number, that is 0 or 1. The size is 32, because we assume that the size of an integer is 32 bits. */
    unsigned int num;
    printf("Enter number: ");
    scanf("%d", &tmp);

    if(tmp < 0){
        tmp = -tmp;
        tmp = ~tmp;
        tmp++;
    }

    num = tmp; /* it is stored as positive */
    i = 0;
    /* successive divisions by 2 and store each bit in the repective array position */

    while(num > 0){
        bits[i] = num & 1;
        num >>= 1; /* equivalent to num /= 2 */
        i++;
    }
    printf("Binary form: ");
    for(j = i-1; j >= 0; j--)
        printf("%d", bits[j]);
    printf("\n");
    return 0;
}

/* The reason we used the shift operator is to improve performance. However, it is unnecessary most likely, because the compiler would optimize the operation by itself. */