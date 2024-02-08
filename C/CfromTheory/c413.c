/***
 * 
 * Bitwise operators are often used in data coding in network communications. For example, some specific bits in the 
 * header of a Transport Control Protocol (TCP) packet are coded as depicted in Figure 4.1.
 * 
 *  bit8    bit7    bit6    bit5    bit4    bit3    bit2    bit1
 *  ----    ----    ----    ----    ----    ----    ----    ----
 *                  URG     ACK                     SYN     FIN
 * 
 * FIN (bit1): If it is 1, it indicates the release of the TCP connection.
 * 
 * SYN (bit2): If it is 1, it indicates the establishment of the TCP connection. That’s the famous bit responsible 
 * for Denial-of-Service (DoS) flooding attacks, but this is another story ...
 * 
 * ACK (bit5): If it is 1, it indicates the acknowledgment of data reception. 
 * 
 * URG (bit6): If it is 1, it indicates the transfer of urgent data.
 * 
 * Write a program that reads the values of URG, ACK, SYN, and FIN bits and encodes this information in a program
 * variable. Then, the program should decode the value of this variable and display the values of the respective bits.
*/

#include <stdio.h>

int main(void){
    unsigned char temp, urg, ack, syn, fin;
    
    printf("Enter FIN bit: ");
    scanf("%d", &fin);
    
    printf("Enter SYN bit: ");
    scanf("%d", &syn);

    printf("Enter ACK bit: ");
    scanf("%d", &ack);   

    printf("Enter URG bit: ");
    scanf("%d", &urg); 
    
    temp = (urg << 5) + (ack << 4) + (syn << 1) + fin;
    printf("Encoding: %#x\n", temp);

    printf("fin = %d, syn = %d, ack = %d, urg = %d\n", \
        temp & 1, (temp >> 1) & 1, \
        (temp >> 4) & 1, (temp >> 5) & 1);
    return 0;
}