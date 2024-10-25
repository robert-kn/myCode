/*
Write the function any(s1,s2), which returns the first location in a string s1
where any character from the string s2 occurs, or -1 if s1 contains no characters from s2.
(The standard library function strpbrk does the same job but returns a pointer to the
location.)
*/

#include <stdio.h>

int any(char s1[], char s2[]){
    int j, k, pos = -1;
    
    for(k = 0; s2[k] != '\0'; ++k){

        for(j = 0; s1[j] != '\0'; ++j){

            if(s1[j] == s2[k] && s1[j] !=  ' ')
                return j;
        }
    }

    return pos;
}

int main(){
    char s1[] = "hello world";
    char s2[] = "x";
    printf("s1 = %s, s2 = %s\n", s1, s2);
    printf("%d\n", any(s1, s2));
    return 0;
}