// Practice problem 2.42

// Write a function div16 that returns the value x/16 for integer argument x. Your function should not use division, 
// modulus, multiplication, any conditionals (if or ?:), any comparison operators (e.g., <, >, or ==), or any loops. 
// You may assume that data type int is 32 bits long and uses a two’s-complement representation, and that right shifts 
// are performed arithmetically. 

// The only challenge here is to compute the bias without any testing or conditional operations. We use the trick that 
// the expression x >> 31 generates a word with all ones if x is negative, and all zeros otherwise. By masking off the 
// appropriate bits, we get the desired bias value. 


int div16(int x) {
    /* Compute bias to be either 0 (x >= 0) or 15 (x < 0) */
    int bias = (x >> 31) & 0xF;
    return (x + bias) >> 4;
}


// My solution below:

int div16(int x){
	return (x + (1 << 4) - 1) >> 4;
}