/* What is the output of the following program? */

#include <stdio.h>

typedef struct node
{
    int i;
    struct node *next; 
    struct node *prev; 
} node;

int main(void)
{
    node a = {10}, b = {20}, c = {30}, d = {40};

    a.next = &b;
    a.prev = &d;

    b.next = &c;
    b.prev = &a;

    c.next = &d;
    c.prev = &b;

    d.next = &a;
    d.prev = &c;

    printf("%d\n", a.prev->prev->prev->next->i); 
    return 0;
}

/* This program is a simple implementation example of another type of list, a circular double linked list, where each node, except the pointer to the next node, contains another pointer to the 
previous node. Notice that the next pointer of the last node points to the head of the list, while head’s prev pointer points to the last node. printf() beg i n s wit h node a, traverses sequentially 
the d, c, and b nodes, returns back to c and outputs 30. */