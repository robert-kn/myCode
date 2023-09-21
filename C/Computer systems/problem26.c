// Practice problem 2.6

// Using show_int and show_float, we determine that the integer 3510593 has hexadecimal representation 0x00359141, 
// while the floating-point number 3510593.0 has hexadecimal representation 0x4A564504. 


// A. Write the binary representations of these two hexadecimal values. 0x00359141 in binary is 
// 0011 0101 1001 0001 0100 0001. 0x4A564504 in binary is 0100 1010 0101 0110 0100 0101 0000 0100

// B. Shift these two strings relative to one another to maximise the number of matching bits. How many bits match? 21
// C. What parts of the strings do not match? We find all bits of the integer embedded in the floating-point 
// number, except for the most significant bit having value 1. Such is the case for the example in the text as well. 
// In addition, the floating-point number has some nonzero high-order bits that do not match those of the integer. 
  
//     00000000001101011001000101000001
//       01001010010101100100010100000100