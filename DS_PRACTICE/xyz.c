#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    int info;
    struct nodetype *next;
} node;
node *insert_first(node *, int);
node *insert_last(node *, int);
void display(node *);
int main()
{
    int ch = 0, x;
    node *top = NULL;
}