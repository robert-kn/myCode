The following C code

int comp(data_t a, data_t b) {
    return a COMP b;
}

shows a general comparison between arguments a and b, where we can set the data type of the arguments by 
declaring data_t with a typedef declaration, and we can set the comparison by defining COMP with a 
#define declaration.

Suppose a is in %edx and b is in %eax. For each of the following instruction sequences, determine which 
data types data_t and which comparisons COMP could cause the compiler to generate this code. (There can be 
multiple correct answers; you should list them all.)
         b      a       data_t types       comp 
------------------------------------------------
A. cmpl %eax,  %edx        int              <
   setl %al

B. cmpw %ax,   %dx        short             >=
   setge %al   

C. cmpb %al,   %dl        unsigned char      <
   setb %al 

D. cmpl %eax,  %edx       int, unsigned, or  !=    
   setne %al               pointer


/* global edition */

Suppose a is in some portion of %rdx while b is in some portion of %rsi. For each of the following instruction 
sequences, determine which data types data_t and which comparisons COMP could cause the compiler to generate this 
code. (There can be multiple correct answers; you should list them all.)

         b      a       data_t types       comp 
------------------------------------------------
A. cmpl %esi,  %edi        int              <
   setl %al

B. cmpw %si,   %di        short             >=
   setge %al   

C. cmpb %sil,   %dil        unsigned char    <=
   setbe %al 

D. cmpq %rsi,  %rdi         pointer, long       !=
   setne %al                unsigned long int