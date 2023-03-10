#include <stdio.h>

int main(){
    typedef struct CELL * LIST;
    struct CELL {
        int element;
        struct LIST * next;
    };
    return 0;
}