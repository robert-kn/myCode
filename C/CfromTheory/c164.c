/* Write a program that reads double numbers continuously and counts either the
positives or the negatives depending on the definition of a macro. For example, if the CNT_
POS macro is defined, the program should count the positives, otherwise the negatives. If
the user enters 0, the insertion of numbers should terminate.*/

#include <stdio.h>

#define CNT_POS

int main(void)
{
    int cnt = 0;
    double num = 1;
    while(num != 0)
    {
        printf("Enter number: ");
        scanf("%lf", &num);
        #ifdef CNT_POS
            if(num > 0)
                cnt++;
        #else
            if(num < 0)
                cnt++;
        #endif
    }
    printf("Cnt = %d\n", cnt);
    return 0;
}