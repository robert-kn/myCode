#include <stdio.h>

#define MAXLINE 1000

int getLine(char *, int);
void reverseLine(char *, int);


/* Write a function reverse(s) that reverses the character string s . Use it to
write a program that reverses its input a line at a time. */

int main(){
    system("clear");

    int length; // store the length of the stdin

    char line[MAXLINE]; 
    
    while((length = getLine(line, MAXLINE)) > 0){
        reverseLine(line, length);
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
void reverseLine(char s[], int limit){
    int i, j;

    j = 0;

    char reverseArray[limit];

    for(i = (limit - 2); i > -1 && s[i] != '\n'; i--){
        reverseArray[j] = s[i];
        j++; 
    }

    reverseArray[j] = '\n';
    reverseArray[j+1] = '\0';
    printf("%s\n", reverseArray);
}