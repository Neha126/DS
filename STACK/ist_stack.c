#include <stdio.h>
#include <stdlib.h>
typedef struct list
{
    int info;
    struct list *next;
} node;
node *push(node *, int);
node *pop(node *);
void display(node *);
int main()
{
    int ch = 0, x;
    node *head = NULL;
    node *tail = head;
    do
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number you want to insert.");
            scanf("%d", &x);
            tail = push(tail, x);
            if (head == NULL)
                head = tail;
            break;
        case 2:
            if (head == NULL)
                printf("stack is empty");

            head = pop(head);
            break;
        case 3:
            if (head == NULL)
                printf("Nothing to display");
            else
                display(head);
            break;
        case 4:
            return (0);
        }
    } while (ch != 0);
}

node *push(node *tail, int value)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("not enough memory..");
    }
    else
    {
        p->info = value;
        if (tail != NULL)
        {
            tail->next = p;
        }
        tail = p;
    }
    return (tail);
}
node *pop(node *head)
{
    node *p;
    printf("%d", head->info);
    p = head;
    head = head->next;
    free(p);
    return (head);
}
void display(node *head)
{
    while (head != NULL)
    {
        printf("\n%d", head->info);
        head = head->next;
    }
}