// Practice Problem 2.33 

// We can represent a bit pattern of length w = 4 with a single hex digit. For a two’s-complement interpretation of  
// these touch problemdigits, fill in the following table to determine the additive inverses of the digits shown: 

// For w = 4, we have TMin4 = −8. So −8 is its own additive inverse, while other values are negated by integer negation. 

// 	x 									- t4 x 
// Hex 	    Decimal 		    Decimal 		       Hex 
//  0			0					0			  		0
//  5			5					-5			 	 	B
//  8			-8					-8			  		8
//  D			-3				 	3			  		3
//  F 		    -1				 	1			  		1

// What do you observe about the bit patterns generated by two’s-complement and unsigned (Problem 2.28) negation? 
// The bit patterns are the same as for unsigned negation. 