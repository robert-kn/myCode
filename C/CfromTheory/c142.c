/* What is the output of the following program? */

#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

void test(char *p);

int main(void)
{
    char *p1, *p2;

    p1 = p2 = (char*) malloc(5);

    if(p1 != NULL)
    {
        strcpy(p1, "example"); test(p2);
        printf("%s\n", p1); 
    }
    return 0;
}

void test(char *p)
{
    printf("%s\n", p); 
    free(p);
}

/* Answer: When malloc() returns, p1 and p2 point to the same memory. When test() is called, we have p = p2 and test() displays example. Since free() releases the memory 
pointed to by p (that’s the same pointed to by p1 and p2), main() displays random characters. */