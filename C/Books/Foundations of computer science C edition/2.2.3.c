/**
 * Write a C function that takes two linked lists of characters as arguments and returns 
 * TRUE if the first string precedes the second in lexicographic order.
*/

#include <stdio.h>

#define DefCell(EltType, CellType, ListType) \ 
typedef struct CellType *ListType;           \ 
struct CellType {                            \
    EltType element;                         \
    ListType next;                           \ 
}

#define FALSE 0
#define TRUE 1


typedef int BOOLEAN;

#define DefCell(char, CELL, LIST)

typedef struct CELL *LIST;

struct CELL{
    char element;
    LIST next;
};

BOOLEAN precedes(LIST, LIST);

int main(){
    return 0;
}

BOOLEAN precedes(LIST a, LIST b){

    // how do i ignore casing??

    if(b == NULL || a == NULL) return FALSE;

    if(a->element == b->element)
        return precedes(a->next, b->next);

    return (a->element < b->element);
}