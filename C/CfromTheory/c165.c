/* Write a program that displays One if both VER_1 and VER_2 macros are not
defined. Otherwise, if either VER_3 or VER_4 macro is defined, the program should dis-
play Two. If nothing from the above happens, it should display Three.*/

#include <stdio.h>

int main(void)
{
#if !defined(VER_1) && !defined(VER_2)
    printf("One\n");
#elif defined(VER_3) || defined(VER_4)
    printf("Two\n");
#else
    printf("Three\n");
#endif
    return 0;
}