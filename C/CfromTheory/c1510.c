/* Assume that the test.txt is a text fle. What would be the output of the following program?*/

#include <stdio.h>

int main(void)
{
    FILE *fp;
    char ch;

    if((fp = fopen("test.txt", "r")) != NULL)
    {
        while(ch = getc(fp) != EOF)
            putc(ch, stdout);
        fclose(fp);
    }
    return 0;
}

/* If the while statement had been written correctly, the program would have dis- played the fle’s characters. Its correct syntax is:

while((ch = getc(fp)) != EOF)

The inner parentheses are needed for reasons of priority. Since they are missing, the expression getc(fp) != EOF is frst executed and its value is 1, as long 
as the end of file is not reached. Therefore, ch becomes 1 and the program displays continuously the character with that ASCII value. When getc() returns EOF, ch becomes 
0 and the loop terminates.*/