#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    struct nodetype *prev;
    int info;
    struct nodetype *next;
} node;
node *insert(node *, int);
void display(node *);
node *delete (node *, int);
int main()
{
    node *head = NULL;
    node *tail = head;
    int ch = 0, x, n;
    do
    {
        printf("\n1.insert\n2.display\n3.display\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the no\n");
            scanf("%d", &x);
            tail = insert(tail, x);
            if (head == NULL)
            {
                head = tail;
            }
            break;
        case 2:
            if (head == NULL)
                printf("nothing to display");
            else
                display(head);
        case 3:
            printf("Enter the no you want to delete")

                case 4 : return (0);
        }
    } while (ch != 0);
}
node *insert(node *tail, int x)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
        printf("memory full\n");
    else
    {
        newnode->info = x;
        if (tail != NULL)
        {
            tail->next = newnode;
        }
        tail = newnode;
    }
    return tail;
}
node *delete (node *head, int n)
{
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->info);
        head = head->next;
    }
}