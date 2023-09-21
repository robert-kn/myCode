// Practice problem 2.15

// Using only bit-level and logical operations, write a C expression that is equivalent to x == y. In other words, it 
// will return 1 when x and y are equal and 0 otherwise. 
// The expression is !(x ^ y). That is, x^y will be zero if and only if every bit of x matches the corresponding bit 
// of y. We then exploit the ability of ! to determine whether a word contains any nonzero bit. 
// There is no real reason to use this expression rather than simply writing x == y, but it demonstrates some of the 
// nuances of bit-level and logical operations.