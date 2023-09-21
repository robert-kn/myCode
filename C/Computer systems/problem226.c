// Practice problem 2.26

// You are given the assignment of writing a function that determines whether one string is longer than another. 
// You decide to make use of the string library function strlen having the following declaration: 

// /* Prototype for library function strlen */
// size_t strlen(const char *s);

// Here is your first attempt at the function: 
// /* Determine whether string s is longer than string t */
// /* WARNING: This function is buggy */

// int strlonger(char *s, char *t) {
//     return strlen(s) - strlen(t) > 0;
// }

// When you test this on some sample data, things do not seem to work quite right. You investigate further and determine 
// that, when compiled as a 32-bit program, data type size_t is defined (via typedef) in header file stdio.h to be unsigned. 

// A. For what cases will this function produce an incorrect result? The function will incorrectly return 1 when s is 
// shorter than t. 
// B. Explain how this incorrect result comes about.
// Since strlen is defined to yield an unsigned result, the difference and the comparison are both computed using unsigned
// arithmetic. When s is shorter than t, the difference strlen(s) - strlen(t) should be negative, but instead becomes a 
// large, unsigned number, which is greater than 0. 
// C. Show how to fix the code so that it will work reliably. 
// return strlen(s) > strlen(t);