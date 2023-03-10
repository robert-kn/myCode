#include <stdio.h>
#include <string.h>
 
int main()
{
   char *str = "hello";
   char *p = str;
   int i=0;
   int len = strlen(str);

   printf("First Loop\n");
   printf("----------\n");
   while(i<len)
   {
      printf("str[i] : %c\n", str[i]);
      ++i;
   }

   printf("\nSecond Loop\n");
   printf("-----------\n");
   while(*p)
   {
      printf("p : %s\n", p);
      ++p;
   }

   return 0;
}