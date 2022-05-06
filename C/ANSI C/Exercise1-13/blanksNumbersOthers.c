#include <stdio.h>

/* Count digits white spaces and others */

int main(){
    system("clear");
    int character, i, nWhite, nOther;
    int nDigits[10];

    nWhite = nOther = 0;
    for(i = 0; i < 10; i++)
        nDigits[i] = 0;

    while((character = getchar()) != EOF){
        if(character >= '0' && character <= '9'){
            ++nDigits[character - '0'];
        }
        else if(character == ' ' || character == '\n' || character == '\t'){
            ++nWhite;
        }
        else {  
            ++nOther;
        }
    }

    printf("digits =");
    for(i = 0; i < 10; ++i)
        printf(" %d", nDigits[i]);
    printf(", white space = %d, other = %d\n", nWhite, nOther);
    return 0;

}