#include <stdio.h>

static char input[2048]; // declares a global array buffer that will store at most 2047 chars as a string of
                         // chars

/* unfortunately you are unable to move the cursor around the input when this program runs because this 
behaviour is not default in the linux and Mac Os. You have to use the editline library and replace the fputs and
fgets functions with functions provided by the editline library*/
int main(int argc, char **argv){
    system("clear");
    puts("Lispy Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    while(1){
        fputs("lispy> ", stdout);  // writes every character from the null terminated string to the output stream 
                                   // specified (stdout)
        fgets(input, 2048, stdin); // reads at most 2048 - 1 characters from stdin (file stream) and stores them in 
                                   // the character array specified by the input variable
        printf("No you're a %s", input);
    }
    return 0;
}