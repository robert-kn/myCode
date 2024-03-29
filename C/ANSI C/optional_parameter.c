#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char *line, int max);

/* find: print lines that match pattern from 1st arg */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long line_number = 0;
    int c, except = 0, number = 0, found = 0;

    while(--argc > 0 && (*++argv)[0] == '-'){
        while(c = *++argv[0]){
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }
        }
    }

    if(argc != 1)
        printf("usage: find -x -n pattern\n");
    else
        while(getLine(line, MAXLINE)> 0){
            line_number++;
            if((strstr(line, *argv) != NULL ) != except){
                if(number)
                    printf("%ld: ", line_number);
                printf("%s", line);
                found++;
            }
        }
    return found;
}