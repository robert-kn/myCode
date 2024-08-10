/* What is the output of the following program? */

#include <stdio.h>

int main(void)
{
    char *arr[] = {"TEXT", "SHOW", "OPTIM", "DAY"};
    char **ptr1;

    ptr1 = arr; 
    printf("%s ", *++ptr1);
    printf("%s", *++ptr1+2);
    printf("%c\n", **++ptr1+1);
    return 0;
}

/* The arr array is declared as an array of pointers to strings. In particular, arr[0] points to "TEXT", 
arr[1] points to "SHOW", and so on. The statement ptr1 = arr; makes ptr1 to point to the address of arr[0].

The expression ++ptr1 makes ptr1 point to arr[1]. Since *++ptr1 is equivalent to arr[1], the program displays 
SHOW.

Similarly, the expression ++ptr1+2 makes frst ptr1 to point to arr[2]. Since *++ptr1 is equivalent to arr[2], 
printf() is equivalent to printf("%s", ptr[2]+2); and the program skips the frst two characters of "OPTIM" 
and displays TIM.

Like before, the expression ++ptr1+1 makes frst ptr1 to point to arr[3]. Therefore, **++ptr1 is equivalent 
to *arr[3]. What is the value of *arr[3]? Since arr[3] points to the frst character of "DAY", *arr[3] is 
equal to 'D'. Therefore, the value of *arr[3]+1 is 'E' and the program displays E.

As a result, the program displays: SHOW TIME
*/