The following C code

int test(data_t a) {
    return a TEST 0;
}

shows a general comparison between argument a and 0, where we can set the data type of the argument by 
declaring data_t with a typedef, and the nature of the comparison by declaring TEST with a #define 
declaration. For each of the following instruction sequences, determine which data types data_t and 
which comparisons TEST could cause the compiler to generate this code. (There can be multiple correct 
answers; list all correct ones.)

A. testl    %eax, %eax         int, unsigned int            !=
   setne    %al                pointer

B. testw    %ax, %ax           short                     ==
   sete     %al

C. testb    %al, %al           signed char              >
   setg     %al

D. testw    %ax, %ax           unsigned short           >
   seta     %al


/* global edition */

shows a general comparison between argument a and 0, where we can set the data type of the argument 
by declaring data_t with a typedef, and the nature of the comparison by declaring TEST with a #define 
declaration. The following instruction sequences implement the comparison, where a is held in some 
portion of register %rdi. For each sequence, determine which data types data_t and which comparisons 
TEST could cause the compiler to generate this code. (There can be multiple correct answers; list all 
correct ones.)

A. testq    %rdi, %rdi        long                      >=
   setge    %al               

B. testw    %di, %di          signed short,           == 
   sete     %al               unsigned short

C. testb    %dil, %dil        unsigned char              >
   seta     %al

D. testl    %edi, %edi        int            <=
   setle     %al
