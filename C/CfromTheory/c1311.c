/* In an ISDN network, the SETUP message of the Q.931 signaling protocol is sent by the calling user to the called user to initiate the 
call establishment procedure. A simplifed format of the SETUP message is depicted in Figure 13.2.

The ALERTING message (Figure 13.3) is sent by the ISDN network to the calling user to indicate that the called user is notifed for the 
incoming call (e.g., ring tone). The CONNECT message (Figure 13.4) is sent by the ISDN network to the calling user to indicate that the 
called user accepted the call (e.g., picks up the phone). These messages traverse the ISDN switches along the path between the two users. 
Each node evaluates the content of the received messages. Let’s write a program to simulate this message analysis. Defne the structure 
type isdn_msg with member one union. The members of that union are three structures to represent the SETUP, CONNECT, and ALERTING 
messages. Write a program that reads a byte stream, uses the previous fgures to parse the data, and stores them in the proper union 
member. To parse the data, the program should check the value of the MT feld. Its value in the SETUP, CONNECT, and ALERTING messages 
is 5, 7, and 1, respectively. To get the byte stream, the program should read 100 positive integers in [0, 255] and store them in an 
array. If the user enters -1, the insertion of data should terminate.*/

#include <stdio.h>

typedef unsigned char BYTE;

struct header
{
    BYTE pd; 
    BYTE crv[3]; 
    BYTE mt;
};

struct setup 
{
    BYTE bc[12]; 
    BYTE cpn[20]; 
    BYTE llc[18]; 
    BYTE hlc[5]; 
    BYTE dt[8];
};

struct connect
{
    BYTE bc[4]; 
    BYTE ci[6];
};

struct alerting
{
    BYTE bc[8]; 
    BYTE pi[4];
    BYTE sig[3];
    BYTE hlc[5];
};

struct isdn_msg
{
    struct header hdr; /* Common header for all messages. */
    union
    {
        struct setup set;
        struct connect con;
        struct alerting alrt;
    };
};

int main(void)
{
    BYTE pkt[100];
    int i;
    struct isdn_msg msg;

    for(i = 0; i < 100; i++)
    {
        printf("Enter octet: ");
        scanf("%d", &pkt[i]);
        if(pkt[i] == -1) 
            break;
    }
    msg.hdr.pd = pkt[0];
    for(i = 0; i < 3; i++)
        msg.hdr.crv[i] = pkt[i+1];
    msg.hdr.mt = pkt[4];

    if(msg.hdr.mt == 5) /* SETUP. */
    {
        for(i = 0; i < 12; i++)
            msg.set.bc[i] = pkt[5+i]; 
        
        for(i = 0; i < 20; i++)
            msg.set.cpn[i] = pkt[17+i]; 
        
        for(i = 0; i < 18; i++)
            msg.set.llc[i] = pkt[37+i]; 
        
        for(i = 0; i < 5; i++)
            msg.set.hlc[i] = pkt[55+i]; 
            
        for(i = 0; i < 8; i++)
            msg.set.dt[i] = pkt[60+i]; 
    }
    else if(msg.hdr.mt == 7) /* CONNECT. */ 
    {
        for(i = 0; i < 4; i++)
            msg.con.bc[i] = pkt[5+i]; 
        for(i = 0; i < 6; i++)
            msg.con.ci[i] = pkt[9+i]; 
    }
    else if(msg.hdr.mt == 1) /* ALERTING. */
    {
        for(i = 0; i < 8; i++)
            msg.alrt.bc[i] = pkt[5+i]; 
        for(i = 0; i < 4; i++)
            msg.alrt.pi[i] = pkt[13+i]; 
        for(i = 0; i < 3; i++)
            msg.alrt.sig[i] = pkt[17+i]; 
        for(i = 0; i < 5; i++)
            msg.alrt.hlc[i] = pkt[20+i]; 
    } 
    return 0;
}