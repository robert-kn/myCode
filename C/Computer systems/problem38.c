/* global edition */

// Assume the following values are stored at the indicated memory addresses and registers:

// Address         Value                   Register    Value
// 0x100           0xFF                    %rax        0x100
// 0x108           0xAB                    %rcx        0x1
// 0x110           0x13                    %rdx        0x3
// 0x118           0x11

// Fill in the following table showing the effects of the following instructions, in terms of both the register 
// or memory location that will be updated and the resulting value:

// Instruction                         Destination                Value
// addq %rcx,(%rax)                    0x100                      0x100
// subq %rdx,8(%rax)                   0x108                      0xa8
// imulq $16,(%rax,%rdx,8)             0x118                      0x110
// incq 16(%rax)                       0x110                      0x14
// decq %rcx                           %rcx                       0x0
// subq %rdx,%rax                      %rax                       0xfd                  
 

/* second edition question */

// Suppose we want to generate assembly code for the following C function:

int shift_left2_rightn(int x, int n)
{
    x <<= 2;
    x >>= n;
    return x;
}

// The code that follows is a portion of the assembly code that performs the actual shifts and leaves the final 
// value in register %eax. Two key instructions have been omitted. Parameters x and n are stored at memory 
// locations with offsets 8 and 12, respectively, relative to the address in register %ebp.
 
1. movl   8(%ebp), %eax       Get x
                             
2. sall    $2, %eax           x <<= 2

3. movl    12(%ebp), %ecx     Get n
                            
4. sarl    %cl, %eax          x >>= n





