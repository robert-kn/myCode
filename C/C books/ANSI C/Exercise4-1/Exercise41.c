/* Write the function strindex(s,t) which returns the position of the rightmost
occurrence of t in s, or -1 if there is none. */

#include <string.h>
#include <stdio.h>

char pattern[] = "ould"; /* pattern to search for */

int str_index(char s[], char t[]){
    int i, j, k;
    for(i= strlen(s) - 1; i >= 0; i--){
        for(j=i, k=strlen(t) - 1; s[j] == t[k]; j--, k--)
            ;
        if(k < 0)
            return j;
    }
    return -1;
}

int main(){
    char para[] = {"Re-ped it nearer to the let Desire!"};
    printf("%d\n", str_index(para, pattern));
}

