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
node *insert_last(node *, int);
int main()
{
    node *head = NULL;
    node *tail = head;
    int x, ch = 0, n;
    do
    {
        printf("\n1.insert \n2.delete \n3.display \n4.insert_last\n5.exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the value");
            scanf("%d", &x);
            tail = insert(tail, x);
            if (head == NULL)
            {
                head = tail;
            }
            break;
        case 2:
            printf("enter the value you want to delete");
            scanf("%d", &n);
            head = delete (head, n);
            break;

        case 3:
            if (head == NULL)
                printf("nothing to display...");
            else
                display(head);
            break;
        case 4:
            printf("enter the value");
            scanf("%d", &x);
            head = insert_last(head, x);
            // if (head == NULL)
            // {
            //     head = tail;
            // }
            break;
        case 5:
            return 0;
        }
    } while (ch != 0);
}
node *insert(node *tail, int val)
{
    node *top;
    top = (node *)malloc(sizeof(node));
    if (top == NULL)
        printf("\nmemory full");
    else
    {
        top->data = val;

        if (tail != NULL)
        {
            tail->next = top;
        }
        tail = top;
    }
    return tail;
}
node *insert_last(node *head, int val)
{
    node *top;
    top = (node *)malloc(sizeof(node));
    if (top == NULL)
        printf("\nmemory full");
    else
    {
        top->data = val;
        if (head->next == NULL)
        {
            head->next = top;
        }
        head = top;
        return head;
    }
}
node *delete (node *head, int n)
{
    if (head == NULL)
    {
        printf("node is empty...");
        return head;
    }
    node *temp;
    // If first node is the data we are looking for
    if (head->data == n)
    {
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    node *orignalHead = head;
    while (head != NULL)
    {
        if (head->data == n)
        {
            temp->next = head->next;
            free(head);
            return orignalHead;
        }
        temp = head;
        head = head->next;
    }
    printf("Number not found...");
    return orignalHead;
}

void display(node *head)
{
    while (head != NULL)
    {
        printf("out: %d ", head->data);
        head = head->next;
    }
}