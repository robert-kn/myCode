#include <stdio.h>

#define DefCell(int, CELL, LIST)

typedef struct CELL *LIST;

struct CELL {
    int element;
    LIST next;
};

int main () {
    return 0;
}