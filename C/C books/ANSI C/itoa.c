/* itoa: convert n to characters in s  */

#include <string.h>
#include <stdio.h>
#include <limits.h>

#define MAXLEN 1000

char * reverse(char s[]){
    int c, i, j;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--){
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return s;
}

char * itoa(long int n, char s[]){
    int i;
    long int sign;

    if((sign = n) < 0) /* record sign */
        n = -n;        /* make n positive */
    i = 0;

    do{             /* generate digits in reverse order */
        s[i++] = n % 10  + '0';     /* get next digit */
    }while((n /= 10) > 0);          /* delete it */

    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    
    return reverse(s);
}

int main(){
    char s[MAXLEN];
    printf("%s\n", itoa(LONG_MIN, s));

}