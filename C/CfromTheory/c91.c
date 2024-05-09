/**
 * Write a program that displays the upper and lowercase letters and their ASCII values.
*/

#include <stdio.h>

int main(void)
{
    int i;

    for(i = 0; i < 26; i++)
        printf("%c(%d)-%c(%d)\n", 'a'+i, 'a'+i, 'A'+i, 'A'+i);
    return 0;
}

/**
 * Comments: In ASCII set, the difference between any uppercase letter and the respective lowercase is 32. Therefore, we could write:
 * 
 * printf("%c(%d)-%c(%d)\n", 'a'+i, 'a'+i, 'a'+i-32, 'a'+i-32);
*/