/**
 * Modify your program from Exercise 2.2.3 to ignore the case of letters in comparisons.
*/

/***
 * Modify your program from Exercise 2.2.3 to ignore the case of letters in comparisons.
 * 
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

typedef int BOOLEAN;

struct CHAR{
    char character;
    struct CHAR * next;
};

struct CHAR * create_first();
struct CHAR * create_second();
void  printLinkedList(struct CHAR *);
BOOLEAN precedes(struct CHAR *, struct CHAR *);



int main(){

    struct CHAR * first = create_first();
    struct CHAR * second = create_second();
    printLinkedList(first);
    printLinkedList(second);
    printf("The result of comparing  chars in {ALL} and {and} is %d\n", precedes(first, second));
    

    free(first);
    free(second);
}

struct CHAR * create_first(){

    struct CHAR * head;
    struct CHAR * first = NULL;
    struct CHAR * second = NULL;
    struct CHAR * third = NULL;

    /* allocate memory */
    first = malloc(sizeof(struct CHAR));
    second = malloc(sizeof(struct CHAR));
    third = malloc(sizeof(struct  CHAR));

    /* assign data values */
    first->character = 'A';
    second->character = 'L';
    third->character = 'L';

    /* connect nodes */
    first->next = second;
    second->next = third;
    third->next = NULL;

    /* save  address of first node to head */
    head = first;

    return head;

}

struct CHAR  * create_second(){
    struct CHAR * head;
    struct CHAR * first = NULL;
    struct CHAR * second = NULL;
    struct CHAR * third = NULL;

    /* allocate memory */
    first = malloc(sizeof(struct CHAR));
    second = malloc(sizeof(struct CHAR));
    third = malloc(sizeof(struct  CHAR));

    /* assign data values */
    first->character = 'a';
    second->character = 'n';
    third->character = 'd';

    /* connect nodes */
    first->next = second;
    second->next = third;
    third->next = NULL;

    /* save  address of first node to head */
    head = first;

    return head;
}

void  printLinkedList(struct CHAR * head){
    printf("{");
    while (head != NULL){
        printf("%c", head->character);
        head = head->next;
    }
    printf("}\n");
}

BOOLEAN precedes(struct CHAR * first, struct CHAR * second){

    if(first == NULL) return TRUE;
    if( second == NULL) return FALSE;

    char lower_first = tolower(first->character);
    char lower_second = tolower(second->character);

    if( lower_first == lower_second)
        return  precedes(first->next, second->next);

    return (first->character < second->character);
    
}  



