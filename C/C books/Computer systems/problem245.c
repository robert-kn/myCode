// Practice problem 2.45

// Fill in the missing information in the following table:

// Fractional value				binary representation				decimal representation
// 	1/8								0.001									0.125

// 	3/4							    0.11									0.75

// 	5/16		  					0.0101								   0.3125

// 	43/16							10.1011								   2.6875

// 	9/8								1.001									1.125

// 	47/8							101.111								    5.875

// 	51/16							11.0011									3.1875


// One simple way to think about fractional binary representations is to represent a number as a fraction of the form x/2^(k). We can write this in binary using the  binary representation of x, with the binary point inserted k positions from the right. As an example, for 25/16, we have 25 in base 10 = 110012. We then put the binary point four positions from the right to get 1.10012. 