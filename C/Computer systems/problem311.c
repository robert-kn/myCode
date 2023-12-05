/* from global edition */
It is common to find assembly-code lines of the form

xorq %rcx,%rcx

in code that was generated from C where no exclusive-or operations were present.

A. Explain the effect of this particular exclusive-or instruction and what useful operation it implements.
    - it sets the value of register %rcx to 0 because of the property a ^ a = 0
B. What would be the more straightforward way to express this operation in assembly code?
    - movq $0, %rcx
C. Compare the number of bytes to encode any two of these three different implementations of the same operation.
    - using a disassembler, i can see that the xor operation uses fewer bytes than the mov operation


/* from the second edition */

Modify the assembly code shown for signed division so that it computes the unsigned quotient and 
remainder of numbers x and y and stores the results on the stack.

x at %ebp+8, y at %ebp+12
1 movl 8(%ebp),%eax         Load x into %eax
2 movl $0, %edx             setting  high order bits to 0
3 divl 12(%ebp)             Divide by y
4 movl %eax, 4(%esp)        Store x/y
5 movl %edx, (%esp)         Store x%y