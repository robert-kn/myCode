// Assume the following values are stored at the indicated memory addresses and registers:

// Address         Value               Register    Value
// 0x100           0xFF                %eax        0x100
// 0x104           0xAB                %ecx        0x1
// 0x108           0x13                %edx        0x3
// 0x10C           0x11


// Fill in the following table showing the effects of the following instructions, both in terms of the 
// register or memory location that will be updated and the resulting value:

// Instruction                         Destination         Value
// addl %ecx,(%eax)                    0x100               0x100
// subl %edx,4(%eax)                   0x104               0xa8
// imull $16,(%eax,%edx,4)             0x10C               0x110
// incl 8(%eax)                        0x108               0x14
// decl %ecx                           %ecx                0x0
// subl %edx,%eax                      %eax                0xfd



/* global edition question */

// Consider the following code, in which we have omitted the expression being computed:

short scale3(short x, short y, short z) { 
    short t =  10 * y + z + y * x;
    return t;
}

// Compiling the actual function with gcc yields the following assembly code:

// short scale3(short x, short y, short z)
// x in %rdi, y in %rsi, z in %rdx

// scale3:
//   leaq (%rsi,%rsi,9), %rbx     --> y + 9y = 10y
//   leaq (%rbx,%rdx), %rbx       --> 10y + z
//   leaq (%rbx,%rdi,%rsi), %rbx  --> 10y + z + y * x
//   ret

// Fill in the missing expression in the C code.






