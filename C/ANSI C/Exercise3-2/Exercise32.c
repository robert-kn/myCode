/* Write a function escape(s,t) that converts characters like newline and tab
into visible escape sequences like \n and \t as it copies the string t to s. Use a switch. Write
a function for the other direction as well, converting escape sequences into the real characters.*/

#include <stdio.h>

#define MAXLINE 1000

void reverse_escape(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        switch(s[i]){
            case '\\':
                switch(s[++i]){
                    case 'n':
                        printf("%c", '\n');
                        ++i;
                        break;
                    case 't':
                        printf("%c", '\t');
                        ++i;
                        break;
                }
            default:
                printf("%c", s[i]);
                break;
        }
        ++i;
    }
    printf("\n");
}

void escape(char s[], char t[]) {

    int i, j;
    i = j = 0;
   
    while(t[i] != '\0'){

        switch(t[i]){

            case '\n': 
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        ++i;
    }
    s[j] = '\0';

    printf("%s\n\n", s);
    printf("reverse_escape function output:\n");
    reverse_escape(s);
}



int main(){
    int c, i;
    i = 0;

    char s[MAXLINE];
    char t[MAXLINE];

    while((c = getchar()) != EOF && i < MAXLINE-1)
        t[i++] = c;
    
    t[i] = '\0';

    escape(s, t);

}