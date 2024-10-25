// Practice problem 2.46

// The imprecision of floating-point arithmetic can have disastrous effects. On February 25, 1991, during the first Gulf 
// War, an American Patriot Missile battery in Dharan, Saudi Arabia, failed to intercept an incoming Iraqi Scud missile. 
// The Scud struck an American Army barracks and killed 28 soldiers. The U.S. General Accounting Office (GAO) conducted a 
// detailed analysis of the failure and determined that the underlying cause was an imprecision in a numeric calculation. 

// In this exercise, you will reproduce part of the GAO’s analysis. 

// The Patriot system contains an internal clock, implemented as a counter that is incremented every 0.1 seconds. To 
// determine the time in seconds, the program would multiply the value of this counter by a 24-bit quantity that was a 
// fractional binary approximation to 1/10. In particular, the binary representation of 1/10 is the nonterminating 
// sequence 0.000110011[0011] . . .2, where the portion in brackets is repeated indefinitely. The program approximated 
// 0.1, as a value x, by considering just the first 23 bits of the sequence to the right of the binary point: 
// x = 0.00011001100110011001100. (See Problem 2.51 for a discussion of how they could have approximated 0.1 more 
// precisely.) 

// 	A.	What is the binary representation of 0.1 − x? 0.000000000000000000000001100[1100] . . .2 
// 	B.	what is the approximate decimal value 0.1 - x? 9.54 x 10^(-8)
// 	C.	The clock starts at 0 when the system is first powered up and keeps counting up from there. In this case, the
//         system had been running for around 100 hours. What was the difference between the actual time and the time 
//         computed by the software? 9.54×10−8 × 100 × 60 × 60 × 10 ≈ 0.343 seconds.  
// 	D.	The system predicts where an incoming missile will appear based on its velocity and the time of the last radar
//         detection. Given that a Scud travels at around 2000 meters per second, how far off was its prediction?  
//         0.343×2000≈687meters. 

// Normally, a slight error in the absolute time reported by a clock reading would not affect a tracking computation. 
// Instead, it should depend on the relative time between two successive readings. The problem was that the Patriot 
// software had been upgraded to use a more accurate function for reading time, but not all of the function calls had 
// been replaced by the new code. As a result, the tracking software used the accurate time for one reading and the 
// inaccurate time for the other.