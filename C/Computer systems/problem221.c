// Practice problem 2.21

// Assuming the expressions are evaluated when executing a 32-bit program on a machine that uses two’s-complement 
// arithmetic, fill in the following table describing the effect of casting and relational operations, in the style 
// of Figure 2.19: 

// Expression										type						evaluation
// ———————————————————————————————————————————————————————————————————————————————
// -2147483647-1 == 2147483648U 				    unsigned					    1
// -2147483647-1 < 2147483647					    signed						    1
// -2147483647-1U < 2147483647 				        unsigned				        0
// -2147483647-1 < -2147483647 				        signed						    1
// -2147483647-1U < -2147483647 				    unsigned				        1