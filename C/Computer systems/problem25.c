// Consider the following three calls to show_bytes:
// Int a = 0x87654321;
// byte_pointer ap = (byte_pointer) &a;
// show_bytes(ap, 1);  /* A. */
// show_bytes(ap, 2);  /* B. */
// show_bytes(ap, 3);  /* C. */

// Indicate the values that will be printed by each call on a little endian machine and on a big endian machine:

// A. Little endian:	21		     		big endian:    87
// B. Little endian:	2143				big endian:    8765
// C. Little endian:	214365				big endian:		876543

// Recall that show_bytes enumerates a series of bytes starting from the one with lowest address and working toward the 
// one with highest address. On a little- endian machine, it will list the bytes from least significant to most. 
// On a big-endian machine, it will list bytes from the most significant byte to the least.