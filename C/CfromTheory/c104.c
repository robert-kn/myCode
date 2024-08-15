/**
 * The following program stores two strings in two arrays, swaps them, and displays their 
 * new content. Is there any error?
*/

#include <stdio.h>

int main(void)
{
    char temp[100], str1[100] = "Let see", str2[100] = "Is everything OK?";

    temp = str1;
    str1 = str2;
    str2 = temp;
    printf("%s %s", str1, str2);
    return 0;

}

/**
 * Answer: Recall from Chapter 8 that the name of an array when used as a pointer is a 
 * constant pointer, meaning that it is not allowed to change its value and point to some 
 * other address. Therefore, the statement 
 * temp = str1; is illegal. The same applies for the next two statements, so the program won’t 
 * compile.
*/