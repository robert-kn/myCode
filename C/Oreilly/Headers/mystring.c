#include "mystring.h"
#include <ctype.h>
#include <stdlib.h>

int my_strlen(const char * str){
    int count =  0;

    while((* str) != '\0')
    {
        count++;
        str++;
    }
    return count;
}

int my_countchar(const char * str, char c){
    int count =  0;

    while((* str) != '\0'){

        if((* str)  == c){
            count++;
        }

        str++;
    }    

    return count;
}

void my_strupper(char * str){
    while((* str) != '\0'){
        * str = toupper(* str);
        str++;
    }
}

char * my_strchr(const char * str, char ch){
    
    while((* str) != '\0'){

        if((* str) == ch){
            return str;
        }

        str++;    
    }

    return NULL;
}