/**
 * How many compilation errors can you detect?
*/

#include <stdio.h>

int main(void)
{
    int i, arr[5] = {10, 20, 30, 40, 50};

    for(i = 0; i < 5; i++)
        printf("%d\n", i[arr]);

    printf("%d\n", 2[arr]-3[arr]);
    return 0;
}

/**
 * Did you escape the trap or not? The normal answer to give is that the expression i[arr] is wrong, because arr and not i is declared 
 * as an array. For the same reason, the expressions 2[arr] and 3[arr] seem wrong as well. However, the compiler does not complain. Yes, 
 * you’ve read correctly, it is not a typing error; the compiler has no reason to complain about. And now, what shall we do after that 
 * concept overturning?
 * 
 * Relax, listen to Getting Away With It (All Messed Up) from James and wait for the smoke to clear. Nothing is messed up; let’s see why. 
 * As said, the compiler converts i[arr] to *(i+arr), which is equivalent to *(arr+i), equivalent to arr[i]. For example, 2[arr] is 
 * equivalent to arr[2]. Therefore, the program is compiled successfully and displays the values of the array’s elements, as well as the 
 * difference of arr[2] and arr[3], that is, -10.
 * 
 * In the same “abnormal” sense, could we write the following?
 * int *ptr = arr+4; printf("%d\n", ptr[-2]);
 * 
 * Yes, because ptr[-2] is converted to *(ptr-2), which is equivalent to *(arr+4-2), that is, arr[2], and the program outputs 30.
 * Needless to say that we don’t recommend this reverse syntax; we just used it to demon- strate the close relationship between arrays 
 * and pointers in a really weird way. Forget that you saw it, get it out of your mind, burn the page.
*/