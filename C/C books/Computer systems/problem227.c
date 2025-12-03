// Practice problem 2.27

// Write a function with the following prototype: 
// /* Determine whether arguments can be added without overflow */
// int uadd_ok(unsigned x, unsigned y);

// This function should return 1 if arguments x and y can be added without causing overflow. 

int uadd_ok(unsigned x, unsigned y){
	
	unsigned sum = x + y;
	return sum >= x;

}

// This function is a direct implementation of the rules given to determine whether or not an unsigned addition overflows.