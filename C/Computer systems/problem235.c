// Practice problem 2.35

// You are given the assignment to develop code for a function tmult_ok that will determine whether two arguments can be
//  multiplied without causing overflow. Here is your solution: 

// /* Determine whether arguments can be multiplied without overflow */
// int tmult_ok(int x, int y) {
//     int p = x*y;
//     /* Either x is zero, or dividing p by x gives y */
//     return !x || p/x == y;
// }

// You test this code for a number of values of x and y, and it seems to work properly. Your coworker challenges you, 
// saying, “If I can’t use subtraction to test whether addition has overflowed (see Problem 2.31), then how can you use 
// division to test whether multiplication has overflowed?” 

// Devise a mathematical justification of your approach, along the following lines. First, argue that the case x = 0 is 
// handled correctly. Otherwise, consider w-bit numbers x (x != 0), y, p, and q, where p is the result of performing 
// two’s- complement multiplication on x and y, and q is the result of dividing p by x.

// It is not realistic to test this function for all possible values of x and y. Even if you could run 10 billion tests 
// per second, it would require over 58 years to test all combinations when data type int is 32 bits. On the other hand, 
// it is feasible to test your code by writing the function with data type short or char and then testing it exhaustively. 
// Here’s a more principled approach, following the proposed set of arguments: 

// 1. Show that x . y, the integer product of x and y, can be written in the form x . y = p + t2w, where t != 0 if and 
// only if the computation of p overflows. 

// We know that x . y can be written as a 2w-bit two’s-complement number. Let u denote the unsigned number represented by 
// the lower w bits, and v denote the two’s-complement number represented by the upper w bits. Then, based on Equation 
// 2.3, we can see that x . y = v2w + u. We also know that u = T2Uw(p), since they are unsigned and two’s-complement 
// numbers arising from the same bit pattern, and so by Equation 2.5, we can write u = p + pw−12w, where pw−1 is the most 
// significant bit of p. Letting t = v + pw−1, we have x . y = p + t2w. Letting t = v + pw−1, we have x . y = p + t2w. 

// When t = 0, we have x . y = p; the multiplication does not overflow. When t != 0, we have x . y != p; the multiplication
// does overflow. 

// 2. Show that p can be written in the form p = x.q + r, where |r| < |x|.
// By definition of integer division, dividing p by nonzero x gives a quotient q and a remainder r such that 
// p = x . q + r, and |r| < |x|. (We use absolute values here, because the signs of x and r may differ. For example, 
// dividing −7 by 2 gives quotient −3 and remainder −1.) 

// 3. Show that q = y if and only if r = t = 0. 
// Suppose q = y. Then we have x.y = x.y + r + t2w. From this, we can see that r + t2w = 0. But |r| < |x| ≤ 2w, and so 
// this identity can hold only if t = 0, in which case r = 0. Suppose r = t = 0. Then we will have x . y = x . q, 
// implying that y = q. 

// When x equals 0, multiplication does not overflow, and so we see that our code provides a reliable way to test whether 
// or not two’s-complement multiplication causes overflow.