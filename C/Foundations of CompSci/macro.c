/**
 * This is a macro that generates declarations of cells with two fields. The macro provides two external 
 * definitions: CellName is  the name  of structure of this type, and ListName is a name for the type
 * of pointers to these cells.
*/

#define DefCell(EltType, CellType, ListType)

typedef struct CellType * ListType;

struct CellType{
    EltType element;
    ListType next;
};

/* we can define cells by the macro use */
DefCell(int, CELL,LIST);

/* the macro then expands into */

typedef struct CELL, LIST;

struct CELL{
    int element;
    LIST next;
};

