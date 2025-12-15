// Practice problem 2.30

// Write a function with the following prototype:

// /* Determine whether arguments can be added without overflow */
int tadd_ok(int x, int y);

// This function should return 1 if arguments x and y can be added without causing overflow. 

#include <limits.h>
#include <stdio.h>

// int tadd_ok(int x, int y){

// 	int sum = x + y;
// 	int neg_over = x  < 0 && y < 0 && sum >= 0; 
// 	int pos_over = x >= 0 && y >= 0 && sum < 0;
// 	return !neg_over && !pos_over; 

// }

// This function is a direct implementation of the rules given to determine whether or not a two’s-complement addition overflows. 

// Bitwise version

/* Determine whether arguments can be added without overflow (bitwise version) */
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

int main(void)
{
    printf("int max %d\n", tadd_ok(INT_MAX, INT_MAX));
    printf("int max %d\n", tadd_ok(INT_MIN, INT_MIN));
    printf("int max %d\n", tadd_ok(INT_MIN, INT_MAX));
    return 0;
}

