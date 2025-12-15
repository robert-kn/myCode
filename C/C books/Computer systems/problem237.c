// Practice problem 2.37
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// In 2002, it was discovered that code supplied by Sun Microsystems to implement the XDR library, a widely used facility for sharing data structures between programs, had a security vulnerability arising from the fact that multiplication can overflow without any notice being given to the program. Code similar to that containing the vulnerability is shown below:


/*
  * Illustration of code vulnerability similar to that found in
  * Sun’s XDR library.
  */
 void* copy_elements(void *ele_src[], int ele_cnt, size_t ele_size) {
     /*
      * Allocate buffer for ele_cnt objects, each of ele_size bytes
      * and copy from locations designated by ele_src
      */
     void *result = malloc(ele_cnt * ele_size);
     if (result == NULL)
         /* malloc failed */
        return NULL;
    void *next = result;
    int i;
    for (i=0;i<ele_cnt;i++){
         /* Copy object i to destination */
         memcpy(next, ele_src[i], ele_size);
         /* Move pointer to next memory region */
         next += ele_size;
     }
     return result;
 }

// The function copy_elements is designed to copy ele_cnt data structures, each consisting of ele_size bytes into a buffer allocated by the function. The number of bytes required is computed as ele_cnt * ele_size.
// Imagine, however, that a malicious programmer calls this function with ele_cnt being 1,048,577 (220 + 1) and ele_size being 4,096 (212) with the program compiled for 32 bits. Then the multiplication on line 9 will overflow, causing only 4096 bytes to be allocated, rather than the 4,294,971,392 bytes required to hold that much data. The loop starting at line 15 will attempt to copy all of those bytes, overrunning the end of the allocated buffer, and therefore corrupting other data structures. This could cause the program to crash or otherwise misbehave.
// The Sun code was used by almost every operating system, and in such widely used programs as Internet Explorer and the Kerberos authentication system. The Computer Emergency Response Team (CERT), an organization run by the Carnegie Mellon Software Engineering Institute to track security vulnerabilities and breaches, issued advisory “CA-2002-25,” and many companies rushed to patch their code. Fortunately, there were no reported security breaches caused by this vulnerability.
// A similar vulnerability existed in many implementations of the library function calloc. These have since been patched. Unfortunately, many programmers call allocation functions, such as malloc, using arithmetic expressions as arguments, without checking these expressions for overflow.

// You are given the task of patching the vulnerability in the XDR code shown above for the case where both data types int and size_t are 32 bits. You decide to eliminate the possibility of the multiplication overflowing by computing the number of bytes to allocate using data type uint64_t. You replace the original call to malloc (line 9) as follows:

uint64_t asize = ele_cnt * (uint64_t) ele_size;
void *result = malloc(asize);

// Recall that the argument to malloc has type size_t.

// A. Does your code provide any improvement over the original? 

// this change does not help at all. Even though the computation of asize will be accurate, the call to malloc will cause this value to be converted to a 32-bit unsigned number, and so the same overflow conditions will occur

// B. How would you change the code to eliminate the vulnerability? 

// With malloc having a 32-bit unsigned number as its argument, it cannot possibly allocate a block of more than 2^(32) bytes, and so there is no point attempting to allocate or copy this much memory. Instead, the function should abort and return NULL, as illustrated by the following replacement to the original call to malloc (line 9)

uint64_t required_size = ele_cnt * (uint64_t) ele_size;
size_t request_size = (size_t) required_size;
if (required_size != request_size)
/* Overflow must have occurred. Abort operation */
    return NULL;
void *result = malloc(request_size);
if (result == NULL)
    /* malloc failed */
    return NULL;