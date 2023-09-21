/**
 * Practice problem 2.2

I know that when a value x is a power of 2, that is, x = 2n for some nonnegative integer n, we can readily write x in hexadecimal form by remembering that the binary representation of x is simply 1 followed by n zeros. The hexadecimal digit 0 represents 4 binary zeros. So, for n written in the form i + 4j , where 0 ≤ i ≤ 3, we can write x with a leading hex digit of 1 (i=0), 2 (i=1), 4 (i=2), or 8 (i = 3), followed by j hexadecimal 0s. As an example, for x = 2,048 = 211, we have n = 11 = 3 + 4 . 2, giving hexadecimal representation 0x800. 

N              2n (decimal)         		    2n (hexadecimal) 
9				 512							9 = 1 + 4 x 2 	—> 0x200
19               524288                         19 = 3 + 4 x 4	—> 0x80000
14               16384                          14 = 2 + 4 x 3	—> 0x4000
18       	     262144									0x10000
17				 131072							17 = 1 + 4 x 4	—> 0x20000
5				    32					        5 = 1 + 4 x 1	—> 0x20
7				   128							        0x80
*/