/**
 * Bitwise operators are often used in applications that communicate with the hardware. For example, a 
 * common configuration method used in asynchronous serial communication is eight bit characters, with 
 * one start_bit, one stop_bit, and one parity_bit. The transmission of data is signaled with the start_bit 
 * set to 0 to inform the receiver for arrival of data. The stop_bit indicates the end of the transmission. 
 * For example, the data bits 10100 are encoded as depicted in Figure 4.2.
 * 
 *        start_bit  <-- transmitted data (5 bits) -->  parity_bit stop_bit
 *  ----            -----         ------                           ------
 *           0       1      0       1       0        0      0        1 
 * The sender may optionally transmit a parity_bit, which is used by the receiver to detect transmission errors. 
 * There are two variants of parity: even parity and odd parity. In even parity, the value of the parity_bit is 
 * calculated in a way that the total number of 1s in data plus the parity bit is even. In case of odd parity, 
 * the total number should be odd. In our example, we choose even parity. Therefore, since the number of 1s in 
 * data is two, that is, even, the parity_bit is set to 0.
 * 
 * Write a program that simulates the sender. The program should read the values of five data bits and use even 
 * parity to generate an 8-bit value.
*/

#include <stdio.h>

int main(void){
    unsigned char ones, data, bit1, bit2, bit3, bit4, bit5, parity_bit;

    printf("Enter bit1: "); 
    scanf("%d", &bit1); 
    if(bit1 == 1)
        ones++;
    printf("Enter bit2: "); 
    scanf("%d", &bit2); 
    if(bit2 == 1)
        ones++;

    printf("Enter bit3: "); 
    scanf("%d", &bit3); 
    if(bit3 == 1)
        ones++;

    printf("Enter bit4: "); 
    scanf("%d", &bit4); 
    if(bit4 == 1)
        ones++;

    printf("Enter bit5: "); 
    scanf("%d", &bit5); 
    if(bit5 == 1)
        ones++;

    if(ones & 1) /* It means that the number of 1s is odd. */ 
        parity_bit = 1;
    else
        parity_bit = 0;

    data = (bit1 << 6) + (bit2 << 5) + (bit3 << 4) + (bit4 << 3) + (bit5 << 2) + (parity_bit << 1) + 1;
    printf("%d\n", data);
    return 0;

}

