/**
 * Is the following program error free?
*/

#include <stdio.h> 

int main(void)
{
    char str1[] = "abc";
    char str2[] = "efg";

    str2[4] = 'w';
    printf("%c\n", str1[0]);
    return 0;
}

/**
 * Answer: When str1 is declared, the compiler creates an array of four places, to store the 
 * 'a', 'b', 'c', and '\0' characters. Similarly, it creates the str2 array with four places, 
 * to store the 'e', 'f', 'g', and '\0' characters. 
 * The attempt to store the 'w' character in a position that exceeds the length of str2 is 
 * wrong. In particular, the assignment str2[4] = 'w' overwrites the data out of str2, which 
 * causes unpredictable behavior. For example, the program may display a, but it may also 
 * display w if str1 is stored right after str2 in memory.
*/