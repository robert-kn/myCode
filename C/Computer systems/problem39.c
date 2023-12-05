/* global edition */

// Suppose we want to generate assembly code for the following C function:

long shift_left4_rightn(long x, long n)
{
    x <<= 4;
    x >>= n;
    return x;
}

// The code that follows is a portion of the assembly code that performs the actual shifts and leaves the final 
// value in register %rax. Two key instructions have been omitted. Parameters x and n are stored in registers 
// %rdi and %rsi, respectively.

// long shift_left4_rightn(long x, long n)
// x in %rdi, n in %rsi

shift_left4_rightn:

1. movq    %rdi, %rax  Get x
2. salq    $4, %rax    x <<= 4
3. movl    %esi, %ecx  get n (4 bytes)
4. sarq    %cl, %rax   x >>= n

// Fill in the missing instructions, following the annotations on the right. The right shift 
// should be performed arithmetically.

/* second edition */

// In the following variant of the function of Figure 3.8(a), the expressions have been replaced by blanks:

int arith(int x, int y, int z){
    int t1 = x ^ y;
    int t2 = t1 >> 3;
    int t3 = ~t2;
    int t4 = t3 - z;
    return t4;
}

// The portion of the generated assembly code implementing these expressions is as follows:

x at %ebp+8, y at %ebp+12, z at %ebp+16

1. movl 12(%ebp), %eax
2. xorl 8(%ebp), %eax
3. sarl $3, %eax
4. notl %eax
5. subl 16(%ebp), %eax

// Based on this assembly code, fill in the missing portions of the C code
