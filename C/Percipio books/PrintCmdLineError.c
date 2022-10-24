#include <stdio.h>
#include <stdlib.h> // required for the exit() function

#define stderr __stderrp
 
int main(int argc, char *argv[])
{
   if( argc < 3 )
   {
      fprintf(stderr, "Not enough Arguments: %d\n", argc);
      exit(-1);
   }

   // proceed normally...
}
