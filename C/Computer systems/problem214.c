// Practice problem 2.14

// Suppose that a and b have byte values 0x66 and 0x39, respectively. Fill in the following table indicating the byte values of the different C expressions: 

// Expression								value									Expression									value
//  a & b									0x20									  a && b										0x01
//  a | b									0x7F									  a || b										0x01
//  ~a | ~b								    0xDF									 !a || !b										0x00
//  a & !b									0x00									  a && ~b										0x01