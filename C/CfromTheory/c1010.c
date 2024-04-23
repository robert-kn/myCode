/**
 * What is the output of the following program?
*/

#include <stdio.h>

int main(void)
{
    char *p, *q, s[] = "play";

    p = s+1;
    q = s;
    p[1] = 'x';
    *s = 'a';
    printf("%d %c\n", *q+2, *(q+2));
    return 0;
    
}

/**
 * Answer: Since p points to the address of the second element of the s array, s[2] changes to 'x'. Also, s[0] becomes 'a'. 
 * Because q points to s[0] and the * operator has greater precedence than the + operator, we have *q+2 = 'a'+2. Therefore, 
 * the program outputs the ASCII value of the character two places after 'a'. This is 'c' and the program outputs 99. Since 
 * the value of *(q+2) is equal to s[2], the program outputs x, as well.
*/