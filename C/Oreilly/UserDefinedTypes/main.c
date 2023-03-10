#include <stdio.h>
#include <stdlib.h>
#include "person1.h"

int main(int argc, char * argv[])
{
    /**
     * argv[1] is the name of the input file
     * argv[2] is the name of the output file (sort by name)
     * argv[3] is the name of the output file (sort by age)
    */
   if(argc < 4)
   {
    return EXIT_FAILURE;
   }

   PersonDatabase * perdb = person_read(argv[1]);

   if(perdb == NULL)
   {
    return EXIT_FAILURE;
   }

   Person_print(perdb);

   Person_sortByName(perdb);

   Person_print(perdb);

   if(Person_write(argv[2], perdb) == 0)
   {
    Person_destruct(perdb);
    return EXIT_FAILURE;
   }

   Person_sortByAge(perdb);

   Person_print(perdb);

   if(Person_write(argv[3], perdb) == 0)
   {
    Person_destruct(perdb);
    return EXIT_FAILURE;
   }

   Person_destruct(perdb);
   return EXIT_SUCCESS;
}