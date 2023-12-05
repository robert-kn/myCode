/*Rewrite the function lower, which converts upper case letters to lower case,
with a conditional expression instead of if-else.
*/

#include <stdio.h>

int lower(int c){

    return (c >= 'A' && c <= 'a') ? (c - 'A' + 'a') : c;
    
}

int main(){
    char A = 'A';
    printf("%c\n", lower(A));
}