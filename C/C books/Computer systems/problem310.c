/* second edition */

It is common to find assembly code lines of the form

xorl %edx,%edx

in code that was generated from C where no Exclusive-Or operations were present.

A. Explain the effect of this particular Exclusive-Or instruction and what useful operation it implements.
    - this instruction sets the contents of register %edx  to 0 because of the additive inverse property i.e.
      a ^ a = 0
B. What would be the more straightforward way to express this operation in assembly code?
    - movl $0, %edx
C. Compare the number of bytes to encode these two different implementations of the same operation.
    -  using a disassembler shows that xor operation uses fewer bytes than the movl instruction

/* gloabl edition  */

Consider the following code, in which we have omitted the expression being computed:

short arith3(short x, short y, short z)
{
    short p1 =  y | z; 
    short p2 =  p1 >> 9; 
    short p3 =  ~p2; 
    short p4 =  p3 - y; 
    return p4;
}

The portion of the generated assembly code implementing these expressions is as follows:

short arith3(short x, short y, short z)
x in %rdi, y in %rsi, z in %rdx

arith3:
    orq     %rsi, %rdx
    sarq    $9, %rdx
    notq    %rdx
    movq    %rdx, %bax
    subq    %rsi, %rbx
    ret

Based on this assembly code, fill in the missing portions of the C code.