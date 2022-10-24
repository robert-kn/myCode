#include <stdio.h>
 
int main()
{
   char *ptr1  = "Hello World"; // pointer to a string
   char str1[] = "Hello World"; // a string array of characters
   char *ptr2  = str1; // pointer to a string array

   printf("%s\n", ptr1);
   printf("%s\n", str1);
   printf("%s\n", ptr2);

   return 0;
}
