/* The popular ping command is used to test the communication between two sys-
tems in an IP network, for example, ping www.ntua.gr. Write a program that reads the
command line argument and checks if it is a valid hostname. To be valid, assume that it
should have the form of the example; that is, begin with "www.", and the part after the
second dot should be two or three characters long (e.g., gr). */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int i, len;

    if(argc != 2)
    {
        printf("Wrong number of arguments\n");
        return 0;
    }

    if(strncmp(argv[1], "www.", 4) != 0)
    {
        printf("Name must begin with www.\n");
        return 0;
    }
    len = strlen(argv[1]);
    for(i = 4; i < len; i++)
        if(argv[1][i] == '.')
            break;
    
    if(i == len)
    {
        printf("Second . is missing\n");
        return 0;
    }
    if((len-i-1) != 2 && (len-i-1) != 3)
    {
        printf("The last part should be two or three characters long\n");
        return 0;
    }
    printf("The hostname %s is valid\n", argv[1]);
    return 0;
}