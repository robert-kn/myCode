/*  global edition */

Consider the following function for computing the quotient and remainder of two unsigned 64-bit numbers:

void uremdiv(unsigned long x, unsigned long y, unsigned long *qp, unsigned long *rp) {
    unsigned long q = x/y;
    unsigned long r = x%y;
    *qp = q;
    *rp = r;
}

Modify the assembly code shown for signed division to implement this function.

void remdiv(unsigned long x, unsigned long y, unsigned long *qp, unsigned long *rp)
x in %rdi, y in %rsi, qp in %rdx, rp in %rcx

1 remdiv:
2 movq  %rdx, %r8
3 movq  %rdi, %rax
4 movl  $0, %edx  
5 divq  %rsi
6 movq  %rax, (%r8)
7 movq  %rdx, (%rcx)
8 ret


/* from second edition */

Consider the following C function prototype, where num_t is a data type declared using typedef:

void store_prod(num_t *dest, unsigned x, num_t y) {
    *dest = x*y;
}

gcc generates the following assembly code implementing the body of the computation:

dest at %ebp+8, x at %ebp+12, y at %ebp+16

1 movl      12(%ebp), %eax              get x  
2 movl      20(%ebp), %ecx              Get y_h
3 imull     %eax, %ecx                  Compute s = x*y_h
4 mull      16(%ebp)                    Compute t = x*y_l         
5 leal      (%ecx,%edx), %edx           add s to t_h 
6 movl      8(%ebp), %ecx               get dest
7 movl      %eax, (%ecx)                store t_1
8 movl      %edx, 4(%ecx)               store s+t_h

Observe that this code requires two memory reads to fetch argument y (lines 2 and 4), two multiplies (lines 3 and 4), 
and two memory writes to store the result (lines 7 and 8).

A. What data type is num_t? We can see that the program is performing multiprecision operations on 64-bit data. We 
   can also see that the 64-bit multiply operation (line 4) uses unsigned arithmetic, and so we conclude that num_t 
   is unsigned long long

B. Describe the algorithm used to compute the product and argue that it is correct.
   Let x denote the value of variable x, and let y denote the value of y, which we can write as y = yh . 2^(32) + yl, 
   where yh and yl are the values represented by the high- and low-order 32 bits, respectively. We can therefore 
   compute x.y =x . yh . 2^(32) + x . yl. The full representation of the product would be 96 bits long, but we require only 
   the low-order 64 bits. We can therefore let s be the low-order 32 bits of x . yh and t be the full 64-bit product x. 
   yl, which we can split into high- and low-order parts th and tl. The final result has tl as the low-order part, and 
   s + th as the high-order part.







    





