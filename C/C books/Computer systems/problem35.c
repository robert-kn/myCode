// You are given the following information. A function with prototype

// void decode1(int *xp, int *yp, int *zp);

// is compiled into assembly code. The body of the code is as follows:

// xp at %ebp+8, yp at %ebp+12, zp at %ebp+16
// 1 movl  8(%ebp), %edi
// 2 movl  12(%ebp), %edx
// 3 movl  16(%ebp), %ecx
// 4 movl  (%edx), %ebx
// 5 movl  (%ecx), %esi
// 6 movl  (%edi), %eax
// 7 movl  %eax, (%edx)
// 8 movl  %ebx, (%ecx)
// 9 movl  %esi, (%edi)

// Parameters xp, yp, and zp are stored at memory locations with offsets 8, 12, and 16, respectively, relative to the 
// address in register %ebp.

// Write C code for decode1 that will have an effect equivalent to the assembly code above.

void decode1(int *xp, int *yp, int *zp){
    int ax = * xp;
    int ay = * yp;
    int az = * zp;

    * yp = ax;
    * zp = ay;
    * xp = az;
}


/* global edition */

// You are given the following information. A function with prototype

// void decode1(long *xp, long *yp, long *zp);

// is compiled into assembly code, yielding the following:

// void decode1(long *xp, long *yp, long *zp)
//   xp in %rdi, yp in %rsi, zp in %rdx
// decode1:
//   movq    (%rdi), %r8
//   movq    (%rsi), %rcx
//   movq    (%rdx), %rax
//   movq    %r8, (%rsi)
//   movq    %rcx, (%rdx)
//   movq    %rax, (%rdi)
//   ret

// Parameters xp, yp, and zp are stored in registers %rdi, %rsi, and %rdx, respec- tively.
// Write C code for decode1 that will have an effect equivalent to the assembly code shown.

void decode2(long *xp, long *yp, long *zp){
    long x = *xp;
    long y = *yp;
    long z = *zp;

    *yp = x;
    *zp = y;
    *xp = z;
}










