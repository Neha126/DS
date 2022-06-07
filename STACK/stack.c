/*Name:- Neha
Course:-MCA 2sem Section B
Roll No:-02
//Stack using Linked list using function - call by value
*/
#include <stdio.h>
#include <stdlib.h>
//..........node struct define..........
typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;
//...........function declartaion.......
node *push(node *, int);
node *pop(node *);
void display(node *);
//..............main ...................
int main()
{
    node *top = NULL;
    int ch = 0, x;
    do
    {
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.display");
        printf("\n4.EXIT");
        printf("\nEnter choise\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:

            printf("enter value of node ");
            scanf("%d", &x);
            top = push(top, x); // push function call
            break;

        case 2:
            if (top == NULL)
                printf("STACK IS EMPTY\n");
            else
                top = pop(top); // pop function call
            break;
        case 3:
            display(top);
            break;
        case 4:
            return 0;
        }
    } while (ch != 0);
    return 0;
}
//.............push node.....................
node *push(node *top, int val)
{
    node *p;
    p = (node *)malloc(sizeof(node));
    if (p == NULL)
        printf("\nnot enough memory\n");
    else
    {
        p->info = val;
        p->next = top;
        top = p;
    }
    return top;
}
//.............pop node.....................
node *pop(node *top)
{

    node *p;
    printf("\npoped node is %d", top->info);
    p = top;
    top = top->next;
    free(p);

    return top;
}
//...............display nodes................
void display(node *top)
{
    while (top != NULL)
    {
        printf("%d ", top->info);
        top = top->next;
    }
    printf("\n");
}

/*
----- OUTPUT ----------
ubuntu@su:~/Desktop/DS$ ./stack

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
1
enter value of node 12

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
1
enter value of node 13

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
1
enter value of node 14

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
1
enter value of node 15

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
3
15 14 13 12

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
2

poped node is 15
1.PUSH
2.POP
3.display
4.EXIT
Enter choise
3
14 13 12

1.PUSH
2.POP
3.display
4.EXIT
Enter choise
4
ubuntu@su:~/Desktop/DS$
*/
