#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000

int getLine(char[], int);
int removeChars(char[]);
int countChars(char[]);

/* Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

int main() {
    system("clear");
    
    char line[MAXLINE];

    while(getLine(line, MAXLINE) > 0){

        printf("Sentence has %d characters before characters are removed\n", countChars(line));

        if(removeChars(line) > 0){
            printf("%s\n", line);
            printf("Sentence has %d characters after blank and nl characters are removed\n", countChars(line));
        }
    }

    return 0;
}

int getLine(char s[], int limit){
    int c, i;

    for(i = 0; i < (limit - 1) && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = EOF;
    return i;
}

int removeChars(char * s){
    int i = 0;

    while(s[i] != '\n') /* find new line character */
        ++i;

    --i; /* reference prior character to the newline character */

    while(i >= 0 && (s[i] == ' ' || s[i] == '\t')) /* index will eventually encounter alphanum or other char constant */
        --i;

    if(i >= 0) { /* is it a non blank line? */
        i++;

        s[i] = '\n'; /* put a new line character back */
        i++;

        s[i] = '\0'; /* terminate the string */
    } 
    
    return i;
}

int countChars(char * s){
    int i = 0;

    while(s[i] != '\n')
        ++i;

    return i;
}
