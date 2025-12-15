Consider the following two 9-bit floating-point representations based on the IEEE floating-point format.

Format A

There is 1 sign bit.
There are k = 5 exponent bits. The exponent bias is 15.
There are n = 3 fraction bits.

Format B

There is 1 sign bit.
There are k = 4 exponent bits. The exponent bias is 7.
There are n = 4 fraction bits.

In the following table, you are given some bit patterns in format A, and your task is to convert them to the closest value in format B. If rounding is necessary you should round toward +∞. In addition, give the values of numbers given by the format A and format B bit patterns. Give these as whole numbers (e.g., 17) or as fractions (e.g., 17/64 or 17/2^(6)).


Format A                                              Format B

Bits                    Value                         Bits                      Value

1 01111 00              -9/8                          1 0111 0010               -9/8

0 10110 011

1 00111 010

0 00000 111

1 11100 000

0 10111 100
