// You are given the task of writing a procedure int_size_is_32() that yields 1 when run on a machine for which an int is 32 bits, and yields 0 otherwise. You are not allowed to use the sizeof operator. Here is a first attempt:

// 1 /* The following code does not run properly on some machines */
// 2 int bad_int_size_is_32() {
// 3 /* Set most significant bit (msb) of 32-bit machine */
// 4    int set_msb = 1 << 31;
// 5 /* Shift past msb of 32-bit word */
// 6    int beyond_msb = 1 << 32;
// 7
// 8 /* set_msb is nonzero when word size >= 32 beyond_msb is zero when word size <= 32 */
// 9 
// 10   return set_msb && !beyond_msb;
// 11 }

// When compiled and run on a 32-bit SUN SPARC, however, this procedure returns 0. The following compiler message gives us an indication of the problem:

// warning: left shift count >= width of type

// A. In what way does our code fail to comply with the C standard?

// 1 << 32 is undefined when int is 32 bits. In C, the shift amount must be strictly less than the width in bits of the type being shifted. If int is 32 bits, then 1 << 32 has a shift count equal to the width → undefined behavior. That's exactly what the compiler warning is telling you. Technically, 1 << 31 is also undefined for signed int. For signed types, left-shifting into or past the sign bit, when the result cannot be represented as a signed int, is also undefined. So strictly speaking, 1 << 31 is also not guaranteed to be valid for int.

// B. Modify the code to run properly on any machine for which data type int is at least 32 bits.

int int_size_is_32(void)
{
    unsigned set_msb = 1U << 31; /* bit 31 is set; legal if int has >= 32 bits */
    unsigned beyond_msb = set_msb << 1; // bit 32 set
    return set_msb && !beyond_msb;

}

// C. Modify the code to run properly on any machine for which data type int is at least 16 bits.

int int_size_is_32(void)
{
    unsigned set_msb = 1U << 15;  // safe if int has at least 16 bits
    set_msb <<= 15;               // now at bit 30 (total shift 30)
    set_msb <<= 1;                // now at bit 31

    unsigned beyond_msb = set_msb << 1; // bit 32 (or zero if 32 bit int)
    return set_msb && !beyond_msb;
}

