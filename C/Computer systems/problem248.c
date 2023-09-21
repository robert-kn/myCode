// Practice problem 2.48

// As mentioned in Problem 2.6, the integer 3,510,593 has hexadecimal representation 0x00359141, while the 
// single-precision, floating-point number 3510593.0 has hexadecimal representation 0x4A564504. Derive this 
// floating-point representation and explain the correlation between the bits of the integer and floating-point 
// representations. 

// 3,510,593 bit representation is 0x00359141 which has bit vector [1        101011001000101000001]
// 3510593.0 bit representation is 0x4A564504 which has bit vector [01001010010101100100010100000100]  

// Solution:
// Take the bit vector of 3,510,593 [0000 0000 0011 0101 1001 0001 0100 0001] and convert it to scientific notation which 
// gives [1.1 0101 1001 0001 0100 0001] X 2^21

// The bias for single point precision is 2^(k−1) - 1 where k = 8 which yields 127. This bias is then added to 21 to yield
// 148. This can be represented in a bit number store as [1001 0100]. Finally add two 0 bits at the end of the 
// mantissa/fractional binary number because single point floating point numbers have 23 bits for the fractional part. 
// [10101100100010100000100]. Consequently the floating representation of the number in binary is 
// [1001010010101100100010100000100] which matches the bit representation given in the question.

// If you logically shift the bit vector representing the integer >> 8 you get the following:
// 			        [110101100100010100000100] ---> 3,510,593 bit representation >> 8
// 			[01001010010101100100010100000100] ---> 3510593.0 bit representation

// Basically 21 bits match between the two representations.