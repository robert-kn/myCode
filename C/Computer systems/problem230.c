// Practice problem 2.30

// Write a function with the following prototype:

// /* Determine whether arguments can be added without overflow */
// int tadd_ok(int x, int y);

// This function is a direct implementation of the rules given to determine whether or not a two’s-complement addition 
// overflows. 

// Int tadd_ok(int x, int y){

// 	int sum = x + y;
// 	int neg_over = x  < 0 && y < 0 && sum >= 0; 
// 	int pos_over = x >= 0 && y >= 0 && sum < 0;
// 	return !neg_over && !pos_over; 

// }

// This function should return 1 if arguments x and y can be added without causing overflow. 
