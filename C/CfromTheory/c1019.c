/***
 * What is the output of the following program?
*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[] = "Text", *p = str;
    int i;

    for(i = 0; i < strlen(str)-1; i++, p++)
        printf("%c", p[i]);
    return 0;
}

/***
 * 
 * Answer: Since strlen() returns 4, the loop is executed three times. Let’s trace the iterations: 
 * 
 * First iteration (i = 0): The value of p[0] is displayed, that is, T. 
 * 
 * Second iteration (i++ = 1): Since p is incremented by one, p points to the second char- acter of the string, that is, 'e'. 
 * Since we handle p as an array, p[0] is 'e' and p[1] is 'x'. Therefore, the program outputs x.
 * 
 * Third iteration (i++ = 2): Now, p points to the third character, that is, 'x'. Therefore, p[0] is 'x', p[1] is 't' and p[2] is 
 * equal to '\0'. As a result, the program displays nothing.
 * 
 * To sum up, the program displays: Tx
*/