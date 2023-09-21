// Practice problem 2.52 (I do not understand how to convert the last 3 values)

// Consider the following two 7-bit floating-point representations based on the IEEE floating point format. Neither has a 
// sign bit— they can only represent nonnegative numbers. 
// 1. Format A
// There are k = 3 exponent bits. The exponent bias is 3. There are n = 4 fraction bits. 
// 2. Format B
// There are k = 4 exponent bits. The exponent bias is 7. There are n = 3 fraction bits. 

// Below, you are given some bit patterns in Format A, and your task is to convert them to the closest value in Format B. 
// If necessary, you should apply the round-to- even rounding rule. In addition, give the values of numbers given by the 
// Format A and Format B bit patterns. Give these as whole numbers (e.g., 17) or as fractions (e.g., 17/64). 
// 		Format A 							Format B 
// 	Bits   		Value 				Bits   		Value 
// 011 0000 	  1				 0111 000		 1
// 101 1110		 15/2			 1001 111		 15/2 
// 010 1001		 25/32			 0110 100 	     3/4	    round down
// 110 1111		 31/2			 1011 000	     16			round up
// 000 0001		 1/64			 0001 000		 1/64		deform -> norm