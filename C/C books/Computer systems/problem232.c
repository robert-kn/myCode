
// Practice problem 2.32
int tadd_ok(int x, int y);
#include <limits.h>
#include <stdio.h>
// You are assigned the task of writing code for a function tsub_ok, with arguments x and y, that will return 1 if computing x-y does not cause overflow. Having just written the code for Problem 2.30, you write the following: 

// /* Determine whether arguments can be subtracted without overflow */
// /* WARNING: This code is buggy. */
int tsub_ok(int x, int y) {
	return tadd_ok(x, -y);
}

int tadd_ok(int x, int y) {
    int sum = x + y;

    int sign_x = x >> 31;     // 0 if x >= 0, -1 if x < 0
    int sign_y = y >> 31;     // 0 if y >= 0, -1 if y < 0
    int sign_sum = sum >> 31; // 0 if sum >= 0, -1 if sum < 0

    // Overflow occurs if x and y have the same sign, but sum has a different one
    int overflow = (!(sign_x ^ sign_y)) & (sign_x ^ sign_sum);

    // Return 1 if OK (no overflow), 0 otherwise
    return !overflow;
}
// For what values of x and y will this function give incorrect results? Writing a correct version of this function is left as an exercise (Problem 2.74). 

// This function will give correct values, except when y is TMin. In this case, we will have -y also equal to TMin, and so function tadd_ok will indicate negative overflow anytime x is negative. In fact, the opposite is true: tsub_ok(x, TMin) should yield 1 when x is negative and 0 when it is nonnegative. 
// One lesson to be learned from this exercise is that TMin should be included as one of the cases in any test procedure for a function. 

int main(void)
{
    printf("int max %d\n", tadd_ok(-1, -INT_MIN));
    return 0;
}