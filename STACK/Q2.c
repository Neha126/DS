/*Name:- Neha
Course:-MCA 2sem Section B
Roll No:-02
//Stack using single Linked list (bottom to top)
*/
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
void displayWithRecursion(node *);

int main()
{
    node *top = NULL;
    int ch = 0, x;
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Display with Recursion\n5.exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &x);
            top = push(top, x);
            break;
        case 2:
            if (top == NULL)
            {
                printf("Stack is empty.");
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
        }
    } while (ch != 0);
}
node *push(node *top, int value)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if (p == NULL)
    {
        printf("\nNot enough memory\n");
    }
    else
    {
        p->info = value;
        p->next = top;
        top = p;
    }
    return top;
}
node *pop(node *top)
{
    node *p;
    printf("\nPoped node is %d", top->info);
    p = top;
    top = top->next;
    free(p);
    return top;
}
void display(node *top)
{
    while (top != NULL)
    {
        printf("%d ", top->info);
        top = top->next;
    }
    printf("\n");
}
void displayWithRecursion(node *top)
{

    if (top == NULL)
    {
        return;
    }
    else
    {
        displayWithRecursion(top->next);
        printf("%d ", top->info);
    }
}

/*

---- OUTPUT ----

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 1
    Enter the value: 11

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 1
    Enter the value: 12

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 1
    Enter the value: 13

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 1
    Enter the value: 14

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 1
    Enter the value: 15

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 3
    15 14 13 12 11

    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 4
    11 12 13 14 15
    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 2

    Poped node is 15
    1.Push
    2.Pop
    3.Display
    4.Display with Recursion
    5.exit
    Enter choice: 5

*/