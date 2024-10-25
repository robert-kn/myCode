// Practice problem 2.36

// For the case where data type int has 32 bits, devise a version of tmult_ok (Problem 2.35) that uses the 64-bit 
// precision of data type long long, without using division. 

// With 64 bits, we can perform the multiplication without overflowing. We then test whether casting the product to 
// 32 bits changes the value: 

int tmult_ok(int x, int y){
    /* compute product without overflow */
    long long pll = (long long) x*y;
    /* see if casting  to int preserves  value */
    return pll == (int) pll;
}

// Note that the casting on the right-hand side of line 4 is critical. If we instead wrote the line as 
//     long long pll = x*y;

// the product would be computed as a 32-bit value (possibly overflowing) and then sign extended to 64 bits.