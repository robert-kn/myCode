// You just started working for a company that is implementing a set of procedures to operate on a data structure where 4 signed bytes are packed into a 32-bit unsigned. Bytes within the word are numbered from 0 (least significant) to 3 (most significant). You have been assigned the task of implementing a function for a machine using two's-complement arithmetic and arithmetic right shifts with the following prototype:

/* Declaration of data type where 4 bytes are packed into an unsigned */
typedef unsigned packed_t;

/* Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum);

// That is, the function will extract the designated byte and sign extend it to be a 32-bit int.
// Your predecessor (who was fired for incompetence) wrote the following code:

/* Failed attempt at xbyte */
int xbyte(packed_t word, int bytenum)
{
    return (word >> (bytenum << 3)) & 0xFF;
}

// A. What is wrong with this code? 

// Extracts the byte correctly, but ALWAYS masks with 0xFF, which clears the sign bit. Example: If extracted byte = 1000 0000 (which should be −128). After masking: 1000 0000 & 1111 1111 = 1000 0000 (0x80). But because word is unsigned, the shift is logical, not arithmetic → the result is treated as unsigned before returning as int. It ends up returning 128 instead of −128, because it fails to sign extend.

// B. Give a correct implementation of the function that uses only left and right shifts, along with one subtraction.

// Key idea: To sign-extend a byte, shift the desired byte to the most significant byte position. Then perform an arithmetic right shift back down. Arithmetic right shift guarantees sign extension.

int xbyte(packed_t word, int bytenum)
{
    int shift = (3 - bytenum) << 3;
    return (int) word << shift >> shift;
}