/* Write an alternative version of squeeze(s1,s2) that deletes each character in
s1 that matches any character in the string s2.*/
#include <stdio.h>

/* squeeze: delete all c from s */
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}

/* what does deleting  a character mean?  */

char * squeeze2(char s1[], const char s2[]){
    int i, j, k;

     for (k = 0; s2[k] != '\0'; k++) {

        for (i = j = 0; s1[i] != '\0'; i++)

            if (s1[i] != s2[k]){
                printf("s1[%d] = %c, s2[%d] = %c\n", i, s1[i], k, s2[k]);
                s1[j++] = s1[i];
            }
            printf("%s\n", s1);    
        s1[j] = '\0';
        printf("%s\n", s1);
    }
    return s1;
    
}


int main(){
    char s1[] = "hello world";
    const char s2[] = "me too";
    printf("s1 = %s, s2 = %s\n", s1, s2);
    printf("%s\n", squeeze2(s1, s2));
    return 0;
}