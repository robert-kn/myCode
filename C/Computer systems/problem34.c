// Assume variables v and p declared with types 

// src_t v;
// dest_t *p;

// where src_t and dest_t are data types declared with typedef. We wish to use
// the appropriate data movement instruction to implement the operation

// *p = (dest_t) v;

// where v is stored in the appropriately named portion of register %eax (i.e., %eax, %ax, or %al), while 
// pointer p is stored in register %edx.

// For the following combinations of src_t and dest_t, write a line of assembly code that does the appropriate transfer. 
// Recall that when performing a cast that involves both a size change and a change of “signedness” in C, the operation 
// should change the signedness first (Section 2.2.6).

// src_t               dest_t                 Instruction
// -----------------------------------------------------------------
// int                 int                    movl      %eax, (%edx)
// char                int                    movsbl    %al, (%edx)
// char                unsigned               movsbl    %al, (%edx)
// unsigned char       int                    movzbl    %al, (%edx)
// int                 char                   movb      %al, (%edx)
// unsigned            unsigned char          movb      %al, (%edx)
// unsigned            int                    movl      %eax, (%edx)


/* global edition */

// Assume variables sp and dp are declared with types 

// src_t *sp;
// dest_t *dp;

// where src_t and dest_t are data types declared with typedef. We wish to use
// the appropriate pair of data movement instructions to implement the operation

// *dp = (dest_t) *sp;

// Assume that the values of sp and dp are stored in registers %rdi and %rsi, respectively. For each entry in the table, 
// show the two instructions that implement the specified data movement. The first instruction in the sequence should 
// read from memory, do the appropriate conversion, and set the appropriate portion of register %rax. The second 
// instruction should then write the appropriate portion of %rax to memory. In both cases, the portions may 
// be %rax, %eax, %ax, or %al, and they may differ from one another.

// Recall that when performing a cast that involves both a size change and a change of “signedness” in C, the operation 
// should change the size first (Section 2.2.6).

// src_t                   dest_t                   Instruction                    comments
// -------------------------------------------------------------------------------------------------------
// long                    long                     movq (%rdi), %rax              read 8 bytes
//                                                  movq %rax, (%rsi)              store 8 bytes

// char                    int                      movsbl (%rdi), %eax            convert char to int
//                                                  movl   %eax, (%rsi)            store 4 bytes

// char                    unsigned                 movsbw (%rdi), %eax            convert char to unsigned int
//                                                  movl   %eax, (%rsi)            store 4 bytes

// unsigned char           long                     movzbq (%rdi), %rax            convert char to long int
//                                                  movq   %rax, (%rsi)            store 8 bytes

// int                     char                     movl   (%rdi), %eax            read 4 bytes
//                                                  movb   %al, (%rsi)             store low order byte

// unsigned                unsigned char            movl    (%rdi), %eax           read 4 bytes
//                                                  movb   %al, (%rsi)             store low order byte

// char                    short                    movsbw  (%rdi), %ax            read byte and sign extend
//                                                  movw    %ax, (%rsi)            store 2 bytes


