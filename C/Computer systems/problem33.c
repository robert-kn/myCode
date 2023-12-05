// Each of the following lines of code generates an error message when we invoke the assembler. 
// Explain what is wrong with each line.

// 1 movb $0xF, (%bl)    ---> Cannot use %bl as address register
// 2 movl %ax, (%esp)    ---> l signifies a double word but in this case register %ax has a range of 2 bytes 
// 3 movw (%eax),4(%esp) ---> this is forbidden i.e. moving an object from memory to memory
// 4 movb %ah,%sh        ---> register %sh does not exist in the architecture of IA32
// 5 movl %eax,$0x123    ---> the destination of a move instruction can only be a register or memory reference
// 6 movl %eax,%dx       ---> destination range is not big enough to fit source data
// 7 movb %si, 8(%ebp)   ---> register %si stores a word (w) not a byte


/* from global edition */
// Each of the following lines of code generates an error message when we invoke the assembler. 
// Explain what is wrong with each line.

// movb $0xF, (%ebx)     ---> Cannot use %ebx as address register
// movl %rax, (%rsp)     ---> mismatch between instruction suffix and source register id
// movw (%rax),4(%rsp)   ---> source and destination cannot be memory references
// movb %al,%sl          ---> register %sl does  not exist
// movq %rax,$0x123      ---> destination cannot be immediate
// movl %eax,%dx         ---> Destination operand incorrect size
// movb %si, 8(%rbp)     ---> mismatch between instruction suffix and source register size