/**
 * This program demonstrates CPU virtualisation. Even though you system only has
 * X processors, somehow all four of these programs seem to be running at same 
 * time. How does this magic happen? The OS (with the help of some hardware) is 
 * incharge of this illusion i.e. that the system has a very large number of virtual
 * CPUs.
*/

#include <stdio.h>
#include <stdlib.h>
//#include <sys/time.h>
//#include <assert.h>
#include "common.h"
#include <unistd.h>

int main(int argc, char *argv[])
{
    if(argc != 2){
        fprintf(stderr, "usage: cpu <string>\n");
        exit(1);
    }

    char *str = argv[1];

    while(1){
        Spin(10);
        printf("(%d) %s\n", getpid(), str);
    }
    return 0;
}