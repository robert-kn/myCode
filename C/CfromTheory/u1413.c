/* A double linked list is a list where each node, except the pointer to the next node, contains another 
pointer to the previous node. Write a program that generates 100 random integers and creates a double 
linked list with those integers. Use the following struct to represent the node: */

typedef struct node
{
    int num;
    struct node *next; 
    struct node *prev; 
} node;

Write the following functions:
a. add_list(int num); it creates a new node with value equal to num. 
b. dup_list(void);  if all numbers in the list are different, it returns NULL, other- wise a pointer to the frst node whose num value is the same as a previous one. 
c. del_node(int num); it deletes the node with value equal to num.
d. show_list(void);  it displays the num values of the nodes backwards, starting from the end of the list to the beginning.
e. free_list(void);  it releases the allocated memory starting from the end of the list to the beginning.

The program should call all these functions in that order, to test their operation.