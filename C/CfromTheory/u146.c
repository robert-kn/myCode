/* Write a program that reads 10 double numbers and stores them in a dynamically allocated memory. Then, 
the program should allocate extra memory of the same size and prompt the user to enter a number, as follows: 

a. If it is 0, the program should store the numbers in that new memory in reverse order.
b. If it is 1, the program should store frst the negatives and then the positives.

Use pointer arithmetic to handle the memory regions. For example, assume that the frst memory region contains 
the numbers:

-3.2  4  3  -9.1  7  6  -2  15  9  -37. If the user enters 0, the numbers should be stored in the second 
memory in reverse order: -37 9 15 -2 … If the user enters 1, it should be stored in that order: 
-3.2 -9.1 -2 -37 4 3 …*/