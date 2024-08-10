/* What is the output of the following program? */

#include <stdio.h>
#include <string.h>

void test(char a, char str[], char *ptr);

int main(void)
{
    char *tmp, txt[20] = "abcde";

    tmp = txt;
    test(*(tmp+1), txt+3, &txt[1]);
    printf("%s\n", txt); 
    return 0;
}

void test(char a, char str[], char *ptr)
{
    strcpy(str, "1234"); 
    str[0] = a; 
    ptr[2] = *str + 5;
}

/* Answer: When test() is called, we have:

a. a = *(tmp+1) = *(txt+1) = txt[1] = b.
b. str = txt+3, so, str[0] is equal to txt[3].
c. ptr = &txt[1] = txt+1. Since ptr points to txt[1], ptr[0] is equal to txt[1], ptr[1] is equal to 
txt[2], and ptr[2] is equal to txt[3].

strcpy() copies the string "1234" into the memory that str points to. Since str points to txt[3], the content 
of txt becomes "abc1234".
The statement str[0] = a; is equivalent to txt[3] = a. Since the value of a is equal to 'b', txt[3] becomes 
'b' and the content of txt changes to "abcb234".
As said, the values of str[0] and ptr[2] are equal to txt[3]. Therefore, *str is equal to 'b' and the 
statement ptr[2] = *str+5; is equivalent to txt[3] = 'b'+5; meaning that txt[3] becomes equal to the 
character located fve places after 'b', that is, 'g'.
Therefore, the program displays abcg234.*/