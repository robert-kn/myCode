#include <stdio.h>

#define MAXLINE 1000

int getLine(char *, int);
void reverseLine(char *);


/* Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time. */

int main(){
    system("clear");

    int length; // store the length of the stdin

    char line[MAXLINE]; 
    
    while((length = getLine(line, MAXLINE)) > 0){
        reverseLine(line);
    }
}

int getLine(char s[], int limit){
    int i, c;

    for(i = 0; i < limit && (c = getchar()) != EOF && c != '\n'; i++){ // add all chars from stdin apart from EOF and newline char
        s[i] = c;
    }

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

// assumes sequence of characters always terminates with a newline (EOF marker stripped away)
void reverseLine(char s[]){
    int i, j;
    char temp;

    i = 0;

    while(s[i] != '\n') /* find the new line character in the string */
        ++i;

    if(s[i] == '\n') /* back off to previous character in string */
        --i;

    j = 0;

    while(j < i){
        temp = s[i];
        s[i] = s[j]; /* last char replaced with first char in string */
        s[j] = temp; /* first char replaced by last char */
        --i;
        ++j;
    }

    printf("%s\n", s);
}