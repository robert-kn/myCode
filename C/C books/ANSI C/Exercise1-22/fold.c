/**
 *  Write a program to ``fold'' long input lines into two or more shorter lines after
    the last non-blank character that occurs before the n-th column of input. Make sure your
    program does something intelligent with very long lines, and if there are no blanks or tabs
    before the specified column.
 * 
 */
#include <stdio.h>

#define MAXLINE 100
#define LINECHARS 78

void getLine(char line[], int limit);

int main(){

   char line[MAXLINE];
   getLine(line, MAXLINE);
   return 0;
   
}

void getLine(char line[], int limit){

   int i, c, count, prevChar;
   i = count = prevChar = 0;

   while((c = getchar()) != EOF && c != '\n'){

      if(c == ' ' && (prevChar == '\t' || prevChar == '\n'))
         continue;
      else if(c == '\t' && (prevChar == '\t' || prevChar == ' '))
         continue;
      else{
         line[i] = c;
         prevChar = c;
         count++;
         i++;
      }

      if(count > LINECHARS){
         line[++i] = '\0';
         printf("%s\n", line);
         i = count = 0;
      }
   }
   line[i++] = '\0';
   printf("%s\n", line);
   
}

