#include <stdio.h>
#include <stdlib.h>


/* If we are compiling on Windows compile these functions */
#ifdef _WIN32
#include <string.h>

/* Fake readline function */
char* readline(char* prompt) {
  fputs(prompt, stdout);
  fgets(buffer, 2048, stdin);
  char* cpy = malloc(strlen(buffer)+1);
  strcpy(cpy, buffer);
  cpy[strlen(cpy)-1] = '\0';
  return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}

/* Otherwise include the editline headers */
#else
#include <editline.h>
#endif


/* unfortunately you are unable to move the cursor around the input when this program runs because this 
behaviour is not default in the linux and Mac Os. You have to use the editline library and replace the fputs and
fgets functions with functions provided by the editline library*/

int main(int argc, char **argv){
    system("clear");
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1){
        char *input = readline("lispy> "); // allows reading of input with capability of editing 
        add_history(input); // records the history of inputs so that they can be retrieved by up and down arrows
        printf("No you're a %s\n", input);
        free(input); // free memory referenced by pointer of the most recent input
    }
    return 0;
}