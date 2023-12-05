#include <stdio.h>

#define MAXLINE 1000 /* maximum input line size */

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

/* print the longest line */
int main(){

    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;

    while((len = getLine(line, MAXLINE)) > 0){
        printf("%d, %s\n", len, line);
        if(len > max){
            max = len;
            copy(longest, line);
        }
    }

    if(max > 0)            /* there was a line */
        printf("%s", longest);

    return 0;
    
}

/* getLine: read a line into s, return length */
int getLine(char s[], int limit){
    int c, i, j;

    j = 0;

    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i){

        if(i < (limit - 2)){
            s[j] = c; /* line still in boundaries */
            ++j;
        }
    }

    if(c == '\n'){
        s[j] = c;
        ++j;
        ++i;
    }

    s[j] = '\0';
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){
    
    int i = 0;

    while((to[i] = from[i]) != '\0')
        ++i;
}