// Practice problem 2.32

// You are assigned the task of writing code for a function tsub_ok, with arguments x and y, that will return 1 if 
// computing x-y does not cause overflow. Having just written the code for Problem 2.30, you write the following: 
// /* Determine whether arguments can be subtracted without overflow */
// /* WARNING: This code is buggy. */
// int tsub_ok(int x, int y) {
// 	return tadd_ok(x, -y);
// }

// For what values of x and y will this function give incorrect results? Writing a correct version of this function is 
// left as an exercise (Problem 2.74). 
// This function will give correct values, except when y is TMin. In this case, we will have -y also equal to TMin, and so
// function tadd_ok will indicate negative overflow anytime x is negative. In fact, the opposite is true: tsub_ok(x, TMin)
// should yield 1 when x is negative and 0 when it is nonnegative. 
// One lesson to be learned from this exercise is that TMin should be included as one of the cases in any test procedure 
// for a function. 