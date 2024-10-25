// Suppose register %eax holds value x and %ecx holds value y. Fill in the table below with formulas indicating 
// the value that will be stored in register %edx for each of the given assembly code instructions:

// Instruction                             Result
// leal 6(%eax), %edx                      6 + x
// leal (%eax,%ecx), %edx                  x + y
// leal (%eax,%ecx,4), %edx                x + 4y
// leal 7(%eax,%eax,8), %edx               7 + 9x
// leal 0xA(,%ecx,4), %edx                 0xA + 4y
// leal 9(%eax,%ecx,2), %edx               9 + x + 2y


/* global edition */

// Suppose register %rbx holds value p and %rdx holds value q. Fill in the table below with formulas indicating 
// the value that will be stored in register %rax for each of the given assembly-code instructions:

// Instruction                         Result
// leaq 9(%rdx), %rax                  9 + q
// leaq (%rdx,%rbx), %rax              q + p
// leaq (%rdx,%rbx,3), %rax            q + 3p
// leaq 2(%rbx,%rbx,7), %rax           2 + 8p
// leaq 0xE(,%rdx,3), %rax             14 + 3q
// leaq 6(%rbx,%rdx,7), %rax           6 + p + 7q