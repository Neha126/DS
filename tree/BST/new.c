#include <stdio.h>
#include <stdlib.h>
typedef struct treetype
{
    struct treetype *left;
    int info;
    struct treetype *right;
} tree;
void insert(tree **root, int);
void leaf_node(tree *, int *);
int main()
{
    int ch = 0, x;
    tree *root = NULL;
    int count = 0;
    do
    {
        printf("\n1.insert\n2.leaf_node\n3.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the no you want to insert: ");
            scanf("%d", &x);
            insert(&root, x);
            break;
        case 2:
            leaf_node(root, &count);
            printf("Total leaf_nodes are:%d", count);
            break;
        case 3:
            return (0);
        }
    } while (ch != 0);
}
void insert(tree **rt, int x)
{
    tree *newnode;
    if ((*rt) == NULL)
    {
        newnode = (tree *)malloc(sizeof(tree));
        newnode->info = x;
        newnode->left = NULL;
        newnode->right = NULL;
        *rt = newnode;
    }
    else
    {
        if (x < (*rt)->info)
            insert(&((*rt)->left), x);
        else
            insert(&((*rt)->right), x);
    }
}
void leaf_node(tree *rt, int *ct)
{
    if (rt != NULL)
    {
        if (rt->left == NULL && rt->right == NULL)
        {
            (*ct)++;
        }
        else
        {
            leaf_node(rt->left, ct);
            leaf_node(rt->right, ct);
        }
    }
}