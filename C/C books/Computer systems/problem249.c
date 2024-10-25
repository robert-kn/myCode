// Practice problem 2.49

// A. For a floating-point format with an n-bit fraction, give a formula for the smallest positive integer that cannot  
// be represented exactly (because it would require an n+1-bit fraction to be exact). Assume the exponent field size k  
// is large enough that the range of representable exponents does not provide a limitation for this problem.

// The number has binary representation 1, followed by n 0s, followed by 1, giving value 2^(n+1) + 1. 

// What is the numeric value of this integer for single-precision format (n = 23)? When n = 23, the value is 
// 224 + 1 = 16,777,217. 