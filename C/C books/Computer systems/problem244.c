// Practice problem 2.44

// Assume we are running code on a 32-bit machine using two’s-complement arithmetic for signed values. Right shifts are 
// performed arithmetically for signed values and logically for unsigned values. The variables are declared and 
// initialised as follows: 

int x = foo();   /* Arbitrary value */
int y = bar();   /* Arbitrary value */
unsigned ux = x;
unsigned uy = y;

// For each of the following C expressions, either (1) argue that it is true (evaluates to 1) for all values of x and y, 
// or (2) give values of x and y for which it is false (evaluates to 0): 

// A. (x > 0)||(x-1 < 0) 
// 	False. Let x be −2,147,483,648 (TMin32). We will then have x-1 equal to 2,147,483,647 (TMax32). 

// B. (x & 7)!= 7||(x << 29 <0) 
// 	True. If (x & 7) != 7 evaluates to 0, then we must have bit x2 equal to 1. When shifted left by 29, this will 
//     become the sign bit. 

// C. (x * x)>= 0
// 	False. When x is 65,535 (0xFFFF), x*x is −131,071 (0xFFFE0001). 
//  D. x < 0||-x <= 0
// 	True. If x is nonnegative, then -x is nonpositive. 

// E. x > 0||-x> = 0 
// 	False. Let x be −2,147,483,648 (TMin32). Then both x and -x are negative. 

// F. x + y == uy + ux 
// 	True. Two’s-complement and unsigned addition have the same bit-level be- havior, and they are commutative. 

// G. x *~y + uy*ux == -x 
// 	True. ~y equals -y-1. uy*ux equals x*y. Thus, the left-hand side is equivalent to x*-y-x+x*y. 