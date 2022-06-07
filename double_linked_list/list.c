#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct list
{
    struct list *prev;
    int data;
    struct list *next;
} node;
node *insert(node *, int);
node *delete (node *, int);
void display(node *, bool);
int main()
{
    node *head = NULL;
    node *tail = head;
    int x, n, ch = 0;

    do
    {
        printf("\n1.insert \n2.display\n3.displayReverse\n4.delete\n5.exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the value.");
            scanf("%d", &x);
            tail = insert(tail, x);
            if (head == NULL)
            {
                head = tail;
            }
            break;

        case 2:
            if (head == NULL)
                printf("nothing to display....");
            else
                display(head, false);
            break;
        case 3:
            display(tail, true);
            break;
        case 4:
            printf("enter the value you want to delete");
            scanf("%d", &n);
            if (head == NULL)
            {
                printf("kuch delete nhi hoga kuki head null h");
            }
            else
            {
                head = delete (head, n);
            }
            break;
        case 5:
            return 0;
        }
    } while (ch != 0);
}
node *insert(node *tail, int value)
{
    node *newnode;
    newnode = (node *)malloc(sizeof(node));
    if (newnode == NULL)
        printf("\nmemory full..");
    else
    {
        newnode->data = value;
        if (tail != NULL)
        {
            tail->next = newnode;
            newnode->prev = tail;
        }
        tail = newnode;
    }
    return tail;
}
node *delete (node *head, int n)
{
    node *orignalhead = head;

    if ((head->data) == n)
    {
        printf("%d", head->data);
        head = head->next;
        free(head->prev);
        return head;
    }
    while (head != NULL)
    {
        if (head->data == n)
        {
            printf("%d", head->data);
            (head->prev)->next = head->next;
            if (head->next != NULL)
            {

                (head->next)->prev = head->prev;
            }
            free(head);
            return orignalhead;
        }
        head = head->next;
    }
    printf("number not found..");
    return orignalhead;
}

void display(node *startPointer, bool isReverse)
{

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
}