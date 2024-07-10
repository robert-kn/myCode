/* What is the output of the following program?
*/

#include <stdio.h>

void swap(char *s1, char *s2);

int main(void)
{
   char *p[] = {"Shadow", "Play"};

   swap(p[0], p[1]);

   printf("%s %s\n", p[0], p[1]);
   return 0;
}

void swap(char *s1, char *s2)
{
   char *p;
   
   p = s1;

   s1 = s2;
   s2 = p;
}

/* Answer: What kind of play is that? Did you answer Play Shadow? Read the comments of
C.11.30. It is only the song to change: Shadow Play from Rory Gallagher.
As in test() of C.11.30, swap() takes as arguments the values of the pointers, not their
addresses. Therefore, the swapping has no effect and the program displays Shadow Play.
What we want you to do is to modify the program in order to output Play Shadow. Let’s
see, can you do that? To give you a hint, change the type of the parameters to... find it, no
more to say. */