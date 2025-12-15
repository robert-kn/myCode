Following the bit-level floating-point coding rules, implement the function with the following prototype:

/* Compute –f. If f is NaN, then return f. */
float_bits float_negate(float_bits f);

For floating-point number f, this function computes –f. If f is NaN, your function should simply return f.
Test your function by evaluating it for all 2^(32) values of argument f and comparing the result to what would be obtained using your machine's floating-point operations.
2.93  Following the bit-level floating-point coding rules, implement the function with the following prototype:

/* Compute |f|. If f is NaN, then return f. */
float_bits float_absval(float_bits f);

For floating-point number f, this function computes |f|. If f is NaN, your function should simply return f.
Test your function by evaluating it for all 2^(32) values of argument f and comparing the result to what would be obtained using your machine's floating-point operations.

