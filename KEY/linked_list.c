/*Name:- Neha
Course:-MCA 2sem Section B
Roll No:-02
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int data;
    struct list *next;
} node;
node *insert(node *, int);
node *delete (node *, int);
void display(node *);
int main()
{
    int ch = 0, x, key;
    node *head = NULL;
    node *tail = head;
    do
    {
        printf("\n1.insert\n2.delete\n3.display\n4.exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value you want to insert.");
            scanf("%d", &x);
            tail = insert(tail, x);
            if (head == NULL)
            {
                head = tail;
            }
            break;
        case 2:
            printf("Enter the number you want to delete.");
            scanf("%d", &key);

            head = delete (head, key);
            break;

        case 3:
            if (head == NULL)
            {
                printf("nothing to display..");
            }
            else
                display(head);
            break;
        case 4:
            return (0);
        }
    } while (ch != 0);
}
node *insert(node *tail, int value)
{
    node *start;
    start = (node *)malloc(sizeof(node));
    if (start == NULL)
    {
        printf("\n Not enough memory");
    }
    else
    {
        start->data = value;
        if (tail != NULL)
        {
            tail->next = start;
        }
        tail = start;
    }
    return tail;
}
node *delete (node *head, int key)
{
    if (head == NULL)
    {
        printf("node is empty");
        return head;
    }
    node *p;
    if (head->data == key)
    {
        p = head;
        head = head->next;
        free(p);
        return head;
    }
    node *newhead = head;
    while (head != NULL)
    {
        if (head->data == key)
        {
            p->next = head->next;
            free(head);
            return newhead;
        }
        p = head;
        head = head->next;
    }
    printf("number not found");
    return newhead;
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

/*

---- OUTPUT ----

    1.insert
    2.delete
    3.display
    4.exit

    1
    Enter the value you want to insert.10

    1.insert
    2.delete
    3.display
    4.exit

    1
    Enter the value you want to insert.11

    1.insert
    2.delete
    3.display
    4.exit

    1
    Enter the value you want to insert.12

    1.insert
    2.delete
    3.display
    4.exit

    1
    Enter the value you want to insert.13

    1.insert
    2.delete
    3.display
    4.exit

    1
    Enter the value you want to insert.14

    1.insert
    2.delete
    3.display
    4.exit

    3
    10 11 12 13 14

    1.insert
    2.delete
    3.display
    4.exit

    2
    Enter the number you want to delete.12

    1.insert
    2.delete
    3.display
    4.exit

    3
    10 11 13 14

    1.insert
    2.delete
    3.display
    4.exit

    4
*/