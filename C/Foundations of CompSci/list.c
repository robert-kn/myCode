/**
 * Write a C function that takes two linked lists of characters as arguments and returns TRUE 
 * if the first string precedes the second in lexicographic order. Hint: Implement the algorithm 
 * for comparing character strings that was described in this section. Use recursion by having the 
 * function call itself on the tails of the character strings when it finds that the first characters 
 * of both strings are the same. Alternatively, one can develop an iterative algorithm to do the same.
*/

#include <stdio.h>

typedef struct CELL *LIST;
struct CELL{
    char element;
    struct LIST next;
};