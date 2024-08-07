/* What is the output of the following program? */

#include <stdio.h>

#define no_main(type, name, text, num) type name(void) {printf(text);
return num;}

no_main(int, main, "No main()", 0)

/* Leave the best for the end. “Silver alert,” main() is lost. The program works,
though. The preprocessor replaces type with int, name with main, text with "No
main()" and num with 0. Therefore, the preprocessor expands no_main() to:
int main(void) {printf("No main()"); return 0;}
and the program displays: No main()
Notice that if we were using void instead of int the compilation would fail, because a
void function cannot return a value.*/