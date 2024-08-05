/* Assume that each line of the test.c text fle contains less than 100 characters. What does the following “badly written” program do?*/

#include <stdio.h>
int main(void)
{
    FILE *fp;
    char str[100];
    for(fp = fopen("test.c", "r"); fp && !feof(fp); fgets(str, sizeof(str), fp) ? printf("%s", str) : 1); 
    return fp ? fclose(fp) : 0;
}

/* The program uses fgets() to read and display each line of test.c, while the loop is executed as long as the end of fle is not reached. If fopen() fails, fp would be equal to NULL, the 
loop won’t be executed and the program returns 0. Otherwise, fclose() closes the fle and the program returns its return value.*/