/* For a system to connect to an Internet address, its network card must transmit an Internet Protocol (IP) packet that encapsulates a special TCP segment. The IPv4 header format is depicted in Figure 20.1.
see page 635 and 636 of book

Write a program that reads the source IP address i n x.x.x.x format (each x is an integer in [0, 255]), the destination IP address in x.x.x.x for mat, and the TCP destination port (integer in [1, 65535]) and 
creates an IP packet that encapsulates the proper TCP segment. The program must store the content of the IP packet in hexadecimal format in a user-selected text fle. Each line must contain 16 bytes. Set the 
following values in the IPv4 header:

a. Version = 4.
b. IHL = 5.
c. Total Length = total length of the IP packet, including the TCP data.
d. Protocol = 6.
e. Time to Live = 255.
f. Destination Address = destination IP address.
g. Source Address = source IP address.

Set the following values in the TCP header:

a. Destination Port = destination TCP port.
b. Source Port = 1500.
c. Window = the maximum allowed value.
d. SYN bit = 1.
Set the remaining felds to 0 and assume that there are no Options felds.

The program has one restriction; if the destination IP address starts from 130.140 or 160.170 and the TCP destination port is 80, do not create the IP packet and display a related message.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char BYTE;

void Build_Pkt(int IP_src[], int IP_dst[], int port); 
void Save_Pkt(BYTE pkt[], int len);
int read_text(char str[], int size, int flag);

int main(void)
{
    int IP_src[4], IP_dst[4], TCP_dst_port;

    do
    {
        printf("Enter dst port [1-65535]: ");
        scanf("%d", &TCP_dst_port);
    } while(TCP_dst_port < 1 || TCP_dst_port > 65535);
    
    printf("Enter dst IP (x.x.x.x): ");
    scanf("%d.%d.%d.%d", &IP_dst[0], &IP_dst[1], &IP_dst[2], &IP_dst[3]);

    if(TCP_dst_port == 80)
    {
        if(IP_dst[0] == 130 && IP_dst[1] == 140)
        {
            printf("It isnt allowed to connect to network 130.140.x.x\n");
            return 0;
        }
        else if(IP_dst[0] == 160 && IP_dst[1] == 170)
        {
            printf("It isnt allowed to connect to network 160.170.x.x\n");
            return 0;
        }
    }
    printf("Enter src IP (x.x.x.x): ");
    scanf("%d.%d.%d.%d", &IP_src[0], &IP_src[1], &IP_src[2], &IP_src[3]);

    Build_Pkt(IP_src, IP_dst, TCP_dst_port);
    return 0;
}

void Build_Pkt(int IP_src[], int IP_dst[], int port)
{
    BYTE pkt[40] = {0}; /* Initialize all fields to 0. */ 
    int i, j;

    pkt[0] = 0x45; /* Version, IHL. */
    pkt[8] = 255; /* Time to Live. */
    pkt[9] = 6; /* Protocol = TCP. */
    for(i = 12, j = 0; i < 16; i++, j++)
        pkt[i] = IP_src[j]; /* IP Source. */ 
    for(i = 16, j = 0; i < 20; i++, j++)
        pkt[i] = IP_dst[j]; /* IP Destination. */ 
    pkt[20] = 1500 >> 8; /* TCP Source Port. */ 
    pkt[21] = 1500 & 0xFF;
    pkt[22] = port >> 8; /* TCP Dest Port. */
    pkt[23] = port & 0xFF; 
    pkt[33] = 2; /* SYN bit. */
    pkt[34] = 0xFF; /* The maximum value for the Window field is all  16 bits set to 1. */
    pkt[35] = 0xFF; /* The values of the CheckSum and Urgent Pointer are set in positions 36-40, therefore the total length of the IP packet is 40 bytes. */
    pkt[2] = 0; /* IP Total Length. */ 
    pkt[3] = 40;

    Save_Pkt(pkt, 40);
}

void Save_Pkt(BYTE pkt[], int len)
{
    FILE *fp;
    char name[100];
    int i;

    printf("Enter file name: ");
    read_text(name, sizeof(name), 1);

    fp = fopen(name, "w"); 
    if(fp == NULL)
    {
        printf("Error: fopen() failed\n");
        exit(EXIT_FAILURE);
    }
    for(i = 0; i < len; i++)
    {
        if(i%16 == 0)
            putc('\n', fp);
        fprintf(fp, "%02X ", pkt[i]);
    }
    fclose(fp);
}

int read_text(char str[], int size, int flag) 
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(str);

    if(len > 0)
    {
        if(flag && (str[len-1] == '\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}

/* Do you have any idea about what this program really does? This program is an oversimplifed version of a popular 
application, almost certainly installed in your computer, the firewall. Like this program, a firewall may prevent 
communication to specifc IP addresses and specifc applications (e.g., web servers listen to TCP port 80). In fact, 
the main part of a frewall is nothing more than a sequence of if-else statements.

In a real networking application, this IP packet is encapsulated in a MAC frame (see C.11.38), the hardware of the 
network card encodes the bits of the frame in digital signals (e.g., two different voltage levels to represent 0 
and 1) and forwards the frame to the con- nected router. The router checks the IP destination address, fnds the 
best path to that destination, and forwards the frame to the next router. Yes, we understand, it is all Greek to 
you, we just tried to introduce you to the fascinating world of computer networking.*/