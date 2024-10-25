// Practice problem 2.24

// Suppose we truncate a 4-bit value (represented by hex digits 0 through F) to a 3-bit value (represented as hex digits 
// 0 through 7.) Fill in the table below showing the effect of this truncation for some cases, in terms of the unsigned 
// and two’s-complement interpretations of those bit patterns. 

// 			Hex 									                Unsigned 											Two’s complement 
// Original 			Truncated 			             Original 			        Truncated 				       Original 				Truncated 
//  0					0								0							0							0						0
// 	2					2								2							2							2						2
// 	9					1								9							1							-7						1
// 	B					3								11							3							-5						3
// 	F					7								15							7							-1						-1

// Explain how Equations 2.9 and 2.10 apply to these cases. 

// As Equation 2.9 states, the effect of this truncation on unsigned values is to simply find their residue, modulo 8. 
// The effect of the truncation on signed values is a bit more complex. According to Equation 2.10, we first compute 
// the modulo 8 residue of the argument. This will give values 0 through 7 for arguments 0 through 7, and also for 
// arguments −8 through −1. Then we apply function U2T3 to these residues, giving two repetitions of the sequences 0 
// through 3 and −4 through −1.