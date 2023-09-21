// Practice problem 2.37
#include <stdio.h>
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
    for (i =0;i<ele_cnt;i++){
         /* Copy object i to destination */
         memcpy(next, ele_src[i], ele_size);
         /* Move pointer to next memory region */
         next += ele_size;
     }
     return result;
 }

// You are given the task of patching the vulnerability in the XDR code shown above. You decide to eliminate the 
// possibility of the multiplication overflowing (on a 32- bit machine, at least) by computing the number of bytes to 
// allocate using data type long long unsigned. You replace the original call to malloc (line 10) as follows: 

long long unsigned asize = ele_cnt * (long long unsigned) ele_size;

void *result = malloc(asize);

// A. Does your code provide any improvement over the original?
// This change does not help at all. Even though the computation of asize will be accurate, the call to malloc will cause 
// this value to be converted to a 32-bit unsigned number, and so the same overflow conditions will occur. 

// B. How would you change the code to eliminate the vulnerability, assuming data type size_t is the same as unsigned int,
// and these are 32 bits long? 
// With malloc having a 32-bit unsigned number as its argument, it cannot possibly allocate a block of more than 2^(32) 
// bytes, and so there is no point attempting to allocate or copy this much memory. Instead, the function should abort 
// and return NULL, as illustrated by the following replacement to the original call to malloc (line 10):

long long unsigned required_size = ele_cnt * (long long unsigned) ele_size;
size_t request_size = (size_t) required_size;
if (required_size != request_size)
    /* Overflow must have occurred.  Abort operation */
    return NULL;
void *result = malloc(request_size);
if (result == NULL)
    /* malloc failed */
    return NULL;