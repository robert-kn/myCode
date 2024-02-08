/**
 * Write a program that reads an integer in [0, 255] and the number of shifting bits (e.g., n). The program 
 * should display the sum of:
 * 
 * a. Shifting the input number n places to the left and add the “shifted-off” bits to the right of the number.
 * b. Shifting the input number n places to the right and add the “shifted-off” bits to the left of the number.
 * 
 * For example, if the user enters 42 (binary: 00101010) and 3, the program should display the sum of:
 * 
 * 00101010 << 3 = 01010001 = 81 (the shifted-off bits are: 001) and: 00101010 >> 3 = 01000101 = 69 
 * (the shifted-off bits are: 010). The sum is 150.
 * 
*/