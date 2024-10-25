/**
 * Modify your program from Exercise 2.2.3 to ignore the case of letters in comparisons.
*/

/***
 * Write a C function that takes two linked lists of characters as arguments and returns TRUE if the first string 
 * precedes the second in lexicographic order. Hint: Implement the algorithm for comparing character strings that 
 * was described in this section. Use recursion by having the function call itself on the tails of the character 
 * strings when it finds that the first characters of both strings are the same. Alternatively, one can develop an 
 * iterative algorithm to do the same.
*/

#include <stdio.h>
#include <stdlib.h>


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
    printf("The result of comparing  chars in {all} and {and} is %d\n", precedes(first, second));
    

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
    first->character = 'a';
    second->character = 'l';
    third->character = 'l';

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

    if(first->character == second->character)
        return  precedes(first->next, second->next);

    return (first->character < second->character);
    
}  



