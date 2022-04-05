#include <stdio.h>

/*
"The best programs are written so that computing machines can perform them quickly and so that human beings can 
understand them clearly. A programmer is ideally an essayist who works with traditional aesthetic and literary 
forms as well as mathematical concepts, to communicate the way an algorithm works and to convince a reader that 
the results will be correct." ― Donald Ervin Knuth, Selected Papers on Computer Science
*/

//void printFromLast(char **);
void printFromLast(char passage[][40]) {
    for (int i = 67; i >= 0; i--) {
        printf("%s ", passage[i]);
    }
    printf("\n\n");
}

int main (void) {
    system("clear");
    char text[68][40];
    int i;
    
    for (i = 0; i < 68; i++) {
        scanf("%s", text[i]);
    }

    printf("\n\n");
    
    printFromLast(text);
    
    // for (i = 67; i > -1; i--) {
    //     printf("%s ", text[i]);
    // }
}
