/* Write a function expand(s1,s2) that expands shorthand notations like a-z in
the string s1 into the equivalent complete list abc...xyz in s2. Allow for letters of either
case and digits, and be prepared to handle cases like a-b-c and a-z0-9 and -a-z. Arrange
that a leading or trailing - is taken literally.*/
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXLEN 1000

// void expand(char s1[], char s2[]){
//     int i, j;
//     i = j = 0;
//     // check if hyphen the first char in s1. if so ignore it
//     if(s1[i] == '-'){
//         ++i;
//     }

//     for(; s1[i] != '\0';++i){
//         if(s1[i] == '-'){
//             continue;
//         }
//         else{
//             if(isalpha(s1[i]) && isalpha(s1[i + 2])){
//                 for(;s1[i] <= (s1[i+2]);)
//                     s2[j++] = (s1[i])++;
//             }
//             else if(isdigit(s1[i]) && isdigit(s1[i + 2])){
//                 for(;s1[i] <= s1[i + 2];)
//                     s2[j++] = (s1[i])++;
//                 }
                
//             }
//         }

//         s2[j] = '\0';
// }

void expand(char s1[], char s2[]){

    int i, j;
    i = j = 0;
    int len = strlen(s1);
  
    for(; i < (len - 2); i++){

        if(isalnum(s1[i]) && isalnum(s1[i + 2])){

            int character = s1[i];

            if(s1[i] == s2[j-1])
                continue;
            else
                while(character <= s1[i + 2])
                    s2[j++] = character++;
        }
    }
  
    s2[j] = '\0';
}

int main(){
    int i;
    char s1[MAXLEN] = "-0-9A-Z";
    char s2[MAXLEN];
    expand(s1, s2);
    for(i=0; s2[i] != '\0'; i++)
        printf("%c, ",s2[i]);
    printf("\n");
}