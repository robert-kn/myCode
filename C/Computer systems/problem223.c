// Practice problem 2.23

// Consider the following C functions: 
// int fun1(unsigned word) {
//     return (int) ((word << 24) >> 24);
// } 

// int fun2(unsigned word) {
//     return ((int) word << 24) >> 24;
// } 

// Assume these are executed as a 32-bit program on a machine that uses two’s-complement arithmetic. Assume also that 
// right shifts of signed values are performed arithmetically, while right shifts of unsigned values are performed 
// logically. 

// A. Fill in the following table showing the effect of these functions for several example arguments. You will find it 
// more convenient to work with a hexadecimal representation. Just remember that hex digits 8 through F have their most 
// significant bits equal to 1. 

// 	        w 				      fun1(w) 				 fun2(w) 
//     0x00000076		   	    0x00000076              0x00000076
//     0x87654321		   	    0x00000021              0x00000021
//     0x000000c9               0x000000c9              0xffffffc9
//     0xEDCBA987               0x00000087              0xffffff87

// B. Describe in words the useful computation each of these functions performs. Function fun1 extracts a value from the 
// low-order 8 bits of the argument, giving an integer ranging between 0 and 255. Function fun2 extracts a value from the 
// low-order 8 bits of the argument, but it also performs sign extension. The result will be a number between −128 and 127.


// The expressions in these functions are common program “idioms” for extracting values from a word in which multiple bit 
// fields have been packed. They exploit the zero-filling and sign-extending properties of the different shift operations. 
// Note carefully the ordering of the cast and shift operations. In fun1, the shifts are performed on unsigned variable 
// word and hence are logical. In fun2, shifts are performed after casting word to int and hence are arithmetic. 