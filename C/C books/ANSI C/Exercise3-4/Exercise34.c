/* In a two's complement number representation, our version of itoa does not
handle the largest negative number, that is, the value of n equal to -(2wordsize-1). Explain why
not. Modify it to print that value correctly, regardless of the machine on which it runs. */

because the largest negative int on my system is -9223372036854775808 which is stored by LONG_MIN data type. The largest 
positive int is 9223372036854775807 which is stored by LONG_MAX on my system. The below section in the code

if((sign = n) < 0) /* record sign */
    n = -n;        /* make n positive */

would cause an overflow because LONG_MAX cannot hold 9223372036854775808 (too large by 1). Overflow would occur which 
leads to undefined behaviour.
