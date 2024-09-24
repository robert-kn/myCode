/* What does the following program do? Assume that the fle opens successfully. Easy, think for a moment and see the answer on the next page.*/

#include <stdio.h>

void open_file(char fname[], FILE *fp_w);

int main(void)
{
    FILE *fp = NULL;

    open_file("test.txt", fp); 
    fprintf(fp, "Everything OK\n"); 
    fclose(fp);
    return 0;
}

void open_file(char fname[], FILE *fp_w)
{
    fp_w = fopen(fname, "w");
}

/* Answer: What is it doing? Boom. Fell in the trap? Thunderstruck from AC/ DC. For open_file() to be able to change the value of fp, its address should be passed, otherwise its value remains NULL. 
For example:

void open_file(char fname[], FILE **fp_w)
{
    *fp_w = fopen(fname, "r");
}
and change the call to: open_file("test.txt", &fp);
*/