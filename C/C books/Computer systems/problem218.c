// Practice problem 2.18

// a disassembler is a program that converts an executable program file back to a more readable ASCII form. These files contain many hexadecimal numbers, typically representing values in two's-complement form. Being able to recognize these numbers and understand their significance (for example, whether they are negative or positive) is an important skill.
// For the lines labeled A–I (on the right) in the following listing, convert the hexadecimal values (in 32-bit two's-complement form) shown to the right of the instruction names (sub, mov, and add) into their decimal equivalents:

// 4004d0:     48 81 ec e0 02 00 00    sub     $0x2e0,%rsp         A. (736)

// 4004d7:     48 8b 44 24 a8          mov     –0x58(%rsp),%rax    B. (-88)

// 4004dc:     48 03 47 28             add     0x28(%rdi),%rax     C. (40)

// 4004e0:     48 89 44 24 d0          mov     %rax,–0x30(%rsp)    D. (-48)

// 4004e5:     48 8b 44 24 78          mov     0x78(%rsp),%rax     E. (120)

// 4004ea:     48 89 87 88 00 00 00    mov     %rax,0x88(%rdi)     F. (136)

// 4004fl:     48 8b 84 24 f8 01 00    mov     0x1f8(%rsp),%rax    G. (504)

// 4004f8:     00

// 4004f9:     48 03 44 24 08          add     0x8(%rsp),%rax.     (8)

// 4004fe:     48 89 84 24 c0 00 00    mov     %rax, 0xc0 (%rsp)   H.  (192)

// 400505:     00

// 400506:     48 8b 44 d4 b8          mov     –0x48 (%rsp,$rdx,8),%rax    I. (-72)