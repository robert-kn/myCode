#include <stdio.h>
#include <stdlib.h>

#define MAXCHARS 1000 /* max size of the array */

int getLine(char[], int);

/* Write a program to print all input lines that are longer than 80 characters. */
int main(){
    system("clear");
    int len;
    char line[MAXCHARS]; /* current line being read */

    while((len = getLine(line, MAXCHARS)) > 0)
        if(len > 80){
            printf("%s\n", line);
        }

    return 0;
}


int getLine(char s[], int limit){
    int i, c;

    for(i=0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if(c == '\n'){
        s[i] = '\n';
        ++i;
    }

    s[i] = '\0';
    return i;
}
