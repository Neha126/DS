#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;
node *push(node *, int);
node *pop(node *);
void display(node *);
void displayWithRecursion(node *);
int main()
{
    int ch = 0, x;
    node *top = NULL;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Display_with_recursion\n6.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no.");
            scanf("%d", &x);
            top = push(top, x);
            break;
        case 2:
            if (top == NULL)
            {
                printf("\nStack is empty");
            }
            top = pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            displayWithRecursion(top);
            break;
        case 5:
            return (0);
            break;
        }
    } while (ch != 0);
}
node *push(node *top, int x)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
        printf("not enough memory\n");
    else
    {
        newnode->info = x;
        newnode->next = top;
        top = newnode;
    }
    return top;
}
node *pop(node *top)
{
    node *p;
    printf("\npoped element is: %d", top->info);
    p = top;
    top = top->next;
    free(p);
    return top;
}
void display(node *top)
{
    while (top != NULL)
    {
        printf("%d\n", top->info);
        top = top->next;
    }
}
void displayWithRecursion(node *top)
{
    if (top == NULL)
        return;
    else
    {
        displayWithRecursion(top->next);
        printf("%d\n", top->info);
    }
}