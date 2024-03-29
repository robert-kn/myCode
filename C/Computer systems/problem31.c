
// Practice Problem 3.1 from 2nd  edition
// Assume the following values are stored at the indicated memory addresses and registers:

// Address Value Register  Value
// 0x100   0xFF   %eax     0x100
// 0x104   0xAB   %ecx     0x1
// 0x108   0x13   %edx     0x3
// 0x10C   0x11

// Fill in the following table showing the values for the indicated operands:

// Operand                      Value       comment
// %eax                         0x100       register
// 0x104                        0xAB        absolute address
// $0x108                       0x108       immediate for constant values
// (%eax)                       0xFF        address at 0x100
// 4(%eax)                      0xAB        address at 0x104
// 9(%eax,%edx)                 0x11        Address 0x10C
// 260(%ecx,%edx)               0x13        Address 0x108
// 0xFC(,%ecx,4)                0xFF        Address 0x100
// (%eax,%edx,4)                0x11        Address 0x10C


// Practice Problem 3.1 from the global edition

// Assume the following values are stored at the indicated memory addresses and registers:

// Address        Value            Register   Value
// 0x100          0xFF             %rax       0x100
// 0x104          0xAB             %rcx       0x1
// 0x108          0x13             %rdx       0x3
// 0x10C          0x11


// Fill in the following table showing the values for the indicated operands:

// Operand                        Value             comment
// %rax                           0x100             register
// 0x104                          0xAB              absolute address
// $0x108                         0x108             immediate for constant values
// (%rax)                         0xFF              address at 0x100
// 4(%rax)                        0xAB              address at 0x104
// 9(%rax,%rdx)                   0x11              address at 0x10c
// 260(%rcx,%rdx)                 0x13              address at 0x108
// 0xFC(,%rcx,4)
// (%rax,%rdx,4)                  0x11              address at 0x10C




