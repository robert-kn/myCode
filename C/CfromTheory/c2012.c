/* Suppose that we have created subnets in a Class C IP network. An IP network is specifed as Class C when 
the frst octet (byte) of its IP address is within [192, 223]. Write a program that reads the last octet of 
an IP address and the subnet mask and displays the addresses of all subnets, the broadcast address of each 
subnet, and the subnet in which the IP address belongs to.

For example, suppose that we have a Class C IP network (e.g., x.x.x.x) and the user enters 74. Therefore, we 
have to fnd out in which subnet the IP address x.x.x.74 belongs to. To fnd the subnet, the user must enter 
the subnet mask in one of the two following ways:

a. either enter the last octet of the subnet mask (valid values are 252, 248, 240, 224, 192, 128) or,
b. enter the number of the network bits, which must be an integer in [25, 30].

To fnd out the subnets, we calculate the distance between them:
a. In the frst case, the distance is equal to 256-x, where x is the input number.
b. In the second case, the distance is equal to 2^(32-x), where x is the input number of 
bits. For example, if the user enters 26, the distance is equal to 2^(32-26) = 2^6 = 64.

Starting from the IP address x.x.x.0, the IP address of each subnet starts from a number multiple of the 
distance, while the broadcast IP address is the last address of each subnet. For example, if the distance 
is 64, four subnets (i.e., 256/64) can be created and each subnet starts from an IP address multiple of 64. 
The broadcast address is always one less than the address of the next subnet. The program should display the 
last octet of each IP address, as follows:

Network:     .0    .64   .128  .192
Broadcast:   .63   .127  .191  .255

The valid IP range that may be assigned to a system is the numbers between the subnet address and the 
broadcast address. Therefore, a system with IP address x.x.x.74 is a member of the second subnet because 
its last octet falls in [64, 127].

Although the length of this exercise may discourage you to deal with it, it’d be useful for those who take 
“computer networking” courses to learn in both theoretical and program- ming level a simple method to create 
IP subnets fast. This method works the same for the other two classes, A and B. Of course there are several 
other ways for subnetting; however, this method helped me a lot to confgure easily and quickly IP addresses 
in a router and detect confguration errors in an IP network. I’d defnitely recommend it.*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, j, flag, sel, num, dist, host_byte;

    do
    {
        printf("Enter last host byte [0-255]: "); 
        scanf("%d", &host_byte);
    } while (host_byte < 0 || host_byte > 255);

    do
    {
        flag = 0;
        printf("Enter mask (0: 255.255.255.x form or 1: /bits form): "); 
        scanf("%d", &sel);
        if(sel == 0)
        {
            printf("Enter last mask octet 255.255.255.");
            scanf("%d", &num);
            if(num != 252 && num != 248 && num != 240 && num != 224 && num != 192 && num != 128)
            {
                printf("Last octet should be one of {128, 192, 224, 240, 248, 252}\n");
                flag = 1;
            }
            else
                dist = 256-num;
        }
        else if(sel == 1)
        {
            printf("Enter network bits: /");
            scanf("%d", &num);

            if(num < 25 || num > 30)
            {
                printf("Enter valid mask /25-/30\n");
                flag = 1;
            }
            else
            {
                num = 32-num;
                dist = 1; 
                for(i = 0; i < num; i++)
                    dist = dist*2;   /* For faster implementation we could replace the loop with dist = 1 << num; */
            }
        }
    } while (flag == 1);
    
    printf("\nThe mask 255.255.255.%d produces %d subnets, each with %d hosts\n", 256-dist, 256/dist, dist-2);

    printf("\nNetwork  :  ");
    for(i = 0; i < 256; i+=dist)
        printf(".%d\t", i);

    printf("\nBroadcast:  ");
    for(i = dist-1; i < 256; i+=dist)
        printf(".%d\t", i);
    
    for(i=j=0; i < 256; i+=dist, j++)
    {
        if(host_byte >= i && host_byte < i+dist)
        {
            if(host_byte == i)
                printf("\n\nThe x.x.x.%d address is the network address of subnet_%d\n", host_byte, j+1);
            else if(host_byte == i+dist-1)
                printf("\n\nThe x.x.x.%d address is the broadcast address of subnet_%d\n", host_byte, j+1);
            else
                printf("\n\nThe x.x.x.%d address belongs in subnet %d\n", host_byte, j+1);
            break;
        }
    }
    return 0;
}