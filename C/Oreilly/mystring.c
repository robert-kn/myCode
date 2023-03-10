#include "mystring.h"
#include <ctype.h>
#include <stddef.h> 

// or you can also use the unistd.h to get the NULL keyword to stop being erroring out

int my_strlen(const char * str)
{
    int len = 0;

    while(* str != '\0')
    {
        len++;
        str++;
    }

    return len;
}

int my_countchar(const char * str, char ch)
{
    int count = 0;

    while(* str != '\0')
    {
        if(* str == ch)
        {
            count++;
        }
        str++;
    }
    return count;
}

void my_strupper(char * str)
{
    while(* str != '\0')
    {
        * str = toupper(* str);
        str++;
    }
}


char * my_strchr(const char * str, char ch)
{
    while(*str != '\0')
    {
        if(* str == ch)
        {
            return (char *) str;
        }        
        str++;
    }
    return NULL;
}

