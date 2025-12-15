// Practice problem 2.12

// Write C expressions, in terms of variable x, for the following values. Your code should work for any word size w ≥ 8. For reference, we show the result of evaluating the expressions for x = 0x87654321, with w = 32. 

// A. The least significant byte of x, with all other bits set to 0. [0x00000021] -> x & 0xFF

// B. All but the least significant byte of x complemented, with the least significant byte left unchanged. 
// [0x789ABC21] -> x ^ ~0xFF

// C. The least significant byte set to all ones, and all other bytes of x left unchanged. [0x876543FF] -> x | 0xFF

// These expressions are typical of the kind commonly found in performing low-level bit operations. The expression ~0xFF creates a mask where the 8 least-significant bits equal 0 and the rest equal 1. Observe that such a mask will be generated regardless of the word size. By contrast, the expression 0xFFFFFF00 would only work when data type int is 32 bits.