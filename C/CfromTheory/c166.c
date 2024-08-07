/* What is the output of the following program? */

#include <stdio.h>
#include <string.h>

#define f(text) printf(text); if(strlen(text) < 5) return 0;

int main(void)
{
    f("One");
    f("Two");
    f("Three");
    return 0;
}

/*
The preprocessor expands the first f() to the following lines:

printf("One");
if(strlen("One") < 5)
    return 0;
    
When the program runs, the return statement terminates the program because the
length of One is 3, less than 5. Therefore, the program displays One.*/