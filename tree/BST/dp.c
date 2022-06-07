/*Name:- Neha
Course:-MCA 2sem Section B
Roll No:-02
//
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list
{
    struct list *prev;
    int data;
    struct list *next;

} node;
void insert(node **head, node **tail, int x);
void display(node *, bool);
int main()
{
    node *head = NULL;
    node *tail = head;
    int ch = 0, x;
    do
    {
        printf("\n1.insert\n2.Forward\n3.Reverse\n4.exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter no you wanyt to insert: ");
            scanf("%d", &x);
            insert(&head, &tail, x);
            break;
        case 2:
            display(head, false);
            break;
        case 3:
            display(tail, true);
            break;
        case 4:
            return (0);
        }
    } while (ch != 0);
}
void insert(node **head, node **tail, int x)
{
    node *p, *t;
    p = (node *)malloc(sizeof(node));
    p->data = x;
    p->next = NULL;
    p->prev = NULL;
    if (*head == NULL && *tail == NULL)
    {
        *head = p;
        *tail = p;
    }
    else if (p->data < (*head)->data)
    {
        (*head)->prev = p;
        p->next = *head;
        p->prev = NULL;

        (*head) = p;
    }
    else if (p->data > (*tail)->data)
    {
        (*tail)->next = p;
        p->prev = *tail;
        p->next = NULL;
        (*tail) = p;
    }
    else
    {
        t = *head;
        while ((p->data > (t->next)->data))
        {
            t = t->next;
        }
        (t->next)->prev = p;
        p->next = t->next;
        t->next = p;
        p->prev = t;
    }
}
void display(node *startPointer, bool isReverse)
{
    while (startPointer != NULL)
    {
        printf("%d ", startPointer->data);
        if (isReverse == true)
        {
            startPointer = startPointer->prev;
        }
        else
        {
            startPointer = startPointer->next;
        }
    }
}

/*

---- OUTPUT ----

    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 1

    Enter no you wanyt to insert: 11

    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 1

    Enter no you wanyt to insert: 12

    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 1

    Enter no you wanyt to insert: 13

    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 1

    Enter no you wanyt to insert: 14

    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 2
    11 12 13 14
    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 3
    14 13 12 11
    1.insert
    2.Forward
    3.Reverse
    4.exit
    Enter your choice: 4

*/