/* What is the purpose of the following function? */

unsigned int test(const char *str)
{
    const char *ptr = str;

    while(*str++) /* Equivalent to while(*str++ != '\0')*/
        ;
    return str-ptr-1;
}

/* In each iteration, the loop compares the value of *str with 0, equivalently to '\0', and
then str is increased, to point to the next array element. For example, in the first iteration,
*str is equal to str[0], then it becomes equal to str[1], and so on. Once *str becomes
equal to the null character, the loop terminates.
Recall from Chapter 8 and pointer arithmetic that the result of the subtraction of two
pointers that point to the same array is the number of elements, so, in this example, the
number of characters between them. ptr points to the first element, while str after its
last increase points to the next place following the null character. That’s why we put -1, to
subtract this place.
So, what really does this function do? It does the same thing as the str_len() function
of the previous exercise. It returns the length of the string stored into str. The reason we
added this exercise is to show you that a problem may be solved in several ways, some
simpler and others more complex.
Even if test() is executed a bit faster than str_len() the reader of test() needs
much more time to realize what exactly this function does. Once more, if your program
does not set very strict requirements in speed and efficiency, try to write simple and clear
code for your own benefit and for those who are going to read your code.
In another example of complex coding, the following code uses a for loop instead of a
while loop to produce the same result.
unsigned int test(const char *str)
{
    const char *ptr = str;

    for(; *str; str++)
        ;
    return str-ptr;
}*/