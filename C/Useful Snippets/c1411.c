/* Define the structure type node with members: code, name, grade, and a pointer to a structure of type node. Create a stack whose nodes are structures of that type. Write a program that displays a menu to 
perform the following operations:

1. Insert a student. The program should read the student’s data and store them in a node, which becomes the new head of the stack.
2. Display the data of the stored students.
3. Display the data of the last inserted student.
4. Delete the last inserted student.
5. Display the total number of the stored students.
6. Program termination.

To handle the stack, we use a global pointer. This pointer always points to the head of the stack.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char name[100];
    int code;
    float grd; 
    struct node *next; /* Pointer to the next node. Notice that the existence of the structure tag enables us to declare its type. */
} node;

node *head; /* Global pointer that always points to the head of the stack. */

void add_stack(const node *p);
void show_stack(void);
void pop(void);
int size_stack(void);
void free_stack(void);

int read_text(char str[], int size, int flag);

int main(void)
{
    int sel; 
    node n;

    head = NULL; /* The NULL value indicates an empty stack. */
    while(1)
    {
        printf("\nMenu selections\n"); 
        printf("---------------\n");
        printf("1. Add student\n"); 
        printf("2. View all students\n"); 
        printf("3. View top student\n"); 
        printf("4. Delete top student\n"); 
        printf("5. Number of students\n"); 
        printf("6. Exit\n");
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
            
                add_stack(&n);
            break;

            case 2:
                if(head != NULL)
                    show_stack();
                else
                    printf("\nThe stack is empty\n");
            break;

            case 3:
                if(head != NULL)
                    printf("\nC:%d N:%s G:%.2f\n\n", head->code,head->name,head->grd);
                else
                    printf("\nThe stack is empty\n");
            break;

            case 4:
                if(head != NULL)
                    pop();
                else
                    printf("\nThe stack is empty\n"); 
            break;

            case 5:
                if(head != NULL)
                    printf("\n%d students exist in stack\n", size_stack());
                else
                    printf("\nThe stack is empty\n");
            break;

            case 6:
                if(head != NULL)
                    free_stack(); 
            return 0; 

            default:
                printf("\nWrong choice\n"); 
            break;
        }
    }
    return 0;
}

void add_stack(const node *p)
{
    node *new_node;

    /* Allocate memory to create a new node. */
    new_node = (node*) malloc(sizeof(node));

    if(new_node == NULL)
    {
        printf("Error: Not available memory\n");
        exit(EXIT_FAILURE);
    }
    *new_node = *p; /* Copy the student's data into the new node. */
    new_node->next = head; /* The new node is inserted at the beginning of the stack. For example, when the first node is inserted the value of new_node->next becomes equal to the initial value of head, which is NULL. */
    head = new_node; /* head points to the new node, therefore the new node becomes the new head of the stack. */
}

void show_stack(void)
{
    node *p;

    p = head; 
    printf("\n***** Student Data *****\n\n");

    while(p != NULL)
    {
        printf("C:%d N:%s G:%.2f\n\n", p->code, p->name, p->grd);
        p = p->next; /* In each iteration, p points to the next node. Once it becomes NULL it means that there is no other node left and the loop terminates. */
    }
}

void pop(void)
{
    node *p;
    p = head->next; /* p points to the next node after the head. This node will become the new head of the stack. */
    printf("\nStudent with code =%d is deleted\n", head->code);
    free(head); /* Release the allocated memory. The information about the next node is not lost, because it was saved in p. */
    head = p; /* head points to the new head of the stack. */
}

int size_stack(void)
{
    node *p;
    int num;
    
    num = 0; 
    p = head; 
    
    while(p != NULL)
    {
        p = p->next;
        num++; /* This variable counts the nodes. */
    }
    return num;
}

void free_stack(void)
{
    node *p, *next_node;

    p = head; 
    while(p != NULL)
    {
        next_node = p->next; /* next_node always points to the node after the one to be deleted. */
        free(p); /* Release the allocated memory. The information about the next node is not lost, because it was saved in next_node. */
        p = next_node; /* p points to the next node. */
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

/* a. In add_stack() we pass a pointer and not the structure itself, in order to avoid the creation of a structure’s copy and make faster the execution of the function. 
We declare the pointer as const, just to remember how to prevent modifcations.

b. To display immediately the number of the stored students, without traversing the stack, we could remove the size_stack() function and declare a global variable that 
would be incremented by one each time a student is inserted and decremented when a student is deleted. Once the user selects that menu choice, printf() would display its value. 
It is much simpler and faster. The reason we are using size_stack() is to show you how to traverse the nodes of the stack.

c. If the variable head had been declared locally in main(), we should have passed its address to the functions that need it. For example, add_stack() would change to:

void add_stack(const node *p, node **head_ptr)
{
    node *new_node;

    new_node = (node*) malloc(sizeof(node));
    if(new_node == NULL)
    {
        printf("Error: Not available memory\n");
        exit(EXIT_FAILURE);
    }
    *new_node = *p;
    new_node->next = *head_ptr; 
    *head_ptr = new_node;
}

To call it we’d write: add_stack(&n, &head);
Because we think that this code is more complicated, at least for a beginner, we preferred to declare head as a global variable and use it directly wherever needed.
*/