/* Defne the structure type node with members: code, name, grade, and a pointer to a structure of type node. Create a queue whose nodes are structures of that type. Write a program that displays a 
menu to perform the following operations:

1. Insert a student. The program should read the student’s data and store them in a node, which becomes the new tail of the queue.
2. Display the data of the stored students.
3. Display the data of the last inserted student.
4. Delete the frst inserted student.
5. Program termination.

To handle the queue, we use two global pointers. The frst one always points to the head of the queue and the second one to its tail.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
    char name[100];
    int code;
    float grd; 
    struct node *next; 
} node;

node *head; /* Global pointer that always points to the head of the queue. */
node *tail; /* Global pointer that always points to the tail of the queue. */

void add_queue(const node *p);
void show_queue(void);
void pop(void);
void free_queue(void);

int read_text(char str[], int size, int flag);

int main(void)
{
    int sel; 
    node n;

    head = NULL; 
    while(1)
    {
        printf("\nMenu selections\n");
        printf("---------------\n");
        printf("1. Add student\n");
        printf("2. View all students\n");
        printf("3. View last student\n");
        printf("4. Delete top student\n");
        printf("5. Exit\n");
        
        printf("\nEnter choice: ");
        scanf("%d", &sel);

        switch(sel)
        {
            case 1:
                getchar();

                printf("Name: ");
                read_text(n.name, sizeof(n.name), 1);

                printf("Code: ");
                scanf("%d", &n.code);

                printf("Grade: "); 
                scanf("%f", &n.grd);

                add_queue(&n);
            break;

            case 2:
                if(head != NULL)
                    show_queue();
                else
                    printf("\nThe queue is empty\n"); 
            break;


            case 3:
                if(head != NULL)
                    printf("\nC:%d N:%s G:%.2f\n\n", tail->code,tail->name,tail->grd);
                else
                    printf("\nThe queue is empty\n"); 
            break;


            case 4:
                if(head != NULL)
                    pop();
                else
                    printf("\nThe queue is empty\n"); 
            break;


            case 5:
                if(head != NULL)
                    free_queue(); 
            return 0;

            default:
                printf("\nWrong choice\n"); 
            break;
        }
    }
    return 0;
}

void add_queue(const node *p)
{
    node *new_node;

    new_node = (node*) malloc(sizeof(node));

    if(new_node == NULL)
    {
        printf("Error: Not available memory\n");
        exit(EXIT_FAILURE);
    }

    *new_node = *p;
    new_node->next = NULL;

    if(head == NULL)  
        head = tail = new_node; /* If the queue is empty, both head and tail pointers point to the new node. */
    else
    {
        tail->next = new_node; /* The new node is inserted at the end of the queue. */
        tail = new_node; /* tail points to the last node. */
    }
}

int read_text(char str[], int size, int flag) 
{
    int len;

    if(fgets(str, size, stdin) == NULL)
    {
        printf("Error: fgets() failed\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(str);

    if(len > 0)
    {
        if(flag && (str[len-1] == '\n'))
        {
            str[len-1] = '\0';
            len--;
        }
    }
    else
    {
        printf("Error: No input\n");
        exit(EXIT_FAILURE);
    }
    return len;
}

/* We omit the code of the show_queue(), pop(), and free_queue() func- tions because it is the same as the code of show_stack(), pop(), and free_stack() functions in the stack program. */