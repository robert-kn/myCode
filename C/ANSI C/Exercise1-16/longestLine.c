#include <stdio.h>

int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

/* print longest input line; specialized version */
int main() {
    
    int maxChars;
    printf("Enter the total number of characters you would like the array to hold\n");
    scanf("%d", &maxChars);
    printf("\n\n");

    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[maxChars]; /* current input line */
    char longest[maxChars]; /* longest line saved here */

    printf("Enter the desired input\n\n\n");

    max = 0;
    while ((len = getLine(line, maxChars)) > 0)
        if(len > max) {
            max = len;
            copy(longest, line);
        }
    
    if(max > 0) /* there was a line */
        printf("%s\n", longest);
    
    return 0;

}

/* getline: read a line into s, return length */
int getLine(char s[],int lim){
    int c, i;

    for(i=0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}


/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]){
    int i;
    i = 0;

    while((to[i] = from[i]) != '\0')
        i++;
}






