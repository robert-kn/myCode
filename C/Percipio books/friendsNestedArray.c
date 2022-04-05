#include <stdio.h>
#include <stdlib.h>

/* Allows a user to enter up to five names of friends uses a two dimensional array to store the friends' names.
After each name is entered, the user should have the option to enter another name or print out a report that shows 
each name entered thus far. */

void askUser(char **);
void printNames(char **);

#define numNames 5
#define numChars 20

int main(){
    //! showMemory(cursors=[names[0], names[1], names[2], names[3], names[4]], start=65520)
    system("clear");
    char name1[20];
    char name2[20];
    char name3[20];
    char name4[20];
    char name5[20];
    char * names[5] = {name1, name2, name3, name4, name5};

    for(int i = 0; i < numNames; i++){
        for(int j = 0; j < numChars; j++){
            names[i][j] = '\0';
        }
    }
    
    askUser(names);
    printNames(names);
    return 0;
}

void askUser(char **names){
    int choice = 0;
    int j = 0;
    printf("\nEnter a name: ");
    scanf("%s", names[j]); 
    ++j; // added new name
    while(j < 5){
        printf("\n\nChoose from the following two options:\n");
        printf("\t1. Enter another name.\n");
        printf("\t2. Print the names entered so far.\n");
        printf("\nChoice: ");
        scanf("%d", &choice);
        if(choice == 1){
            printf("\nEnter a name: ");
            scanf("%s", names[j]);
            ++j;
        }
        else if(choice == 2)
            printNames(names);
        
        choice = 0;
    }

}

void printNames(char ** names){
    int i;
    for(i = 0; i < 5; i++){
        printf("Name: %s\n", names[i]);
    }
}