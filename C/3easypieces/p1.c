/**
 *  when this program first starts running, the process prints out a hello world message. Included in that message is its process identifier
 *  also known as a PID. In UNIX systems, the PID is used to name the process if one wants to do something with the process e.g.  stop
 *  it from running. The parent process then calls the fork() system call; which the OS provides as a way to create a new process. The
 *  child process that is created is almost an exact copy of the calling process. That means that to the OS, it now looks like there are 
 *  two copies of the program p1 running, and both are about to return from the fork() system call.
 * 
 *  The newly created processs doesn't start running at the entry of the main function, like you might expect - note that the hello
 *  world message only gets printed out once. Rather it just comes into life as if it had called fork() itself. The child process has
 *  its own copy of the address space i.e. its own private memory, its own registers, its own PC, and so forth. The value it returns to
 *  the caller of fork() is different. Specifically, while the parent receives the PID of the newly created child, the child receives 
 *  a return code of zero. This differentiation is useful, because it is simple then to write code that handles the two different cases.
 * 
 *  The output of this program is not deterministic. When the child process is created, there are now two active processes in the system
 *  that we care about: the parent and the child. Assuming the processes are running on a system with a single CPU (for simplicity), then
 *  either the child or the parent might run at that point. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char * argv[]){
    printf("hello world (pid: %d)\n", getpid());
    int rc = fork();

    if(rc < 0){     /* fork failed; exit */
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if(rc == 0)      /* child (new process) */
        printf("hello, I am child (pid: %d)\n", (int) getpid());
    else                    /* parent goes down this path */
        printf("hello, I am parent of %d (pid: %d)\n", rc, (int) getpid());
    
    return 0;
}