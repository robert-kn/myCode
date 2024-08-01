/* Write a program that reads the names and the score of some candidates and inserts them sorted in a 
linked list. The sorting should be performed when data are entered. The data should be stored in score 
descending order or in alphabetical order. The program should prompt the user to enter the sorting type 
(e.g., 1 for alphabetical). If the user enters end for name, the data insertion should terminate and the 
program should display the list data. Use the following structure to represent the node:*/

typedef struct node
{
    char name[100];
    int score;
    struct node *next; 
} node;

For example, if the user has selected sorting in alphabetical order and the list nodes are:
Arnesen      350
Santer       280

and the user enters the new data Melk and 450, the three list nodes should be in that order:
Arnesen 350
Melk    450
Santer  280