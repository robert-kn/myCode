/**
 *  This program demonstrates how memory is virtualised by the OS. When multiple 
 *  instances of the program are run, you will see that each program will be 
 *  allocated memory at the same address which will be updated independently. It is
 *  as if each running program has its own private memory instead of sharing the 
 *  same physical memory with other running programs. Each process accesses its
 *  own private virtual address space which the OS maps to the physical memory 
 *  of the machine. A memory reference within one running program does not affect 
 *  the address space of other processes (or the OS itself); as far as the 
 *  program is concerned, it has physical memory all to itself. The reality, 
 *  however, is that physical memory is a shared resource, managed by the 
 *  operating system.
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]){
    int * p = malloc(sizeof(int));      /* a1 */
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(), p);      /* a2 */
    *p = 0;                                                         /* a3 */
    while(1){
        Spin(1);
        *p = *p + 1;
        printf("(%d) p: %d\n", getpid(), *p);                       /* a4 */
    }
    return 0;
}