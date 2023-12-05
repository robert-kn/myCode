#include <stdio.h>
#include <string.h>

/* reverse: reverse string s in place */

char * reverse(char s[]){
    int c, i, j;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

int main(){
    char s[] = "I want to help you!";
    printf("reversed string: %s\n", reverse(s));
}