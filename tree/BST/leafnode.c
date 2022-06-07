#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    struct nodetype *left;
    int info;
    struct nodetype *right;
} tree;
void insert(tree **root, int);
void inorder(tree *);
void count_leafnode(tree *, int *);
int main()
{
    int ch = 0, no;
    tree *root = NULL;
    int count = 0;
    do
    {
        printf("\n1.Insert\n2.Inorder\n3.Count_leafnode\n4.Exit\n\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no u want to insert:");
            scanf("%d", &no);
            insert(&root, no);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            count_leafnode(root, &count);
            printf("leaf nodes are %d:", count);
            break;
        case 4:
            return (0);
        }
    } while (ch != 0);
}
void insert(tree **rt, int no)
{
    tree *newnode;
    if ((*rt) == NULL)
    {
        newnode = (tree *)malloc(sizeof(tree));
        newnode->info = no;
        newnode->left = NULL;
        newnode->right = NULL;
        *rt = newnode;
    }
    else
    {
        if (no < (*rt)->info)
            insert(&((*rt)->left), no);
        else
            insert(&((*rt)->right), no);
    }
}
void inorder(tree *rt)
{
    if (rt != NULL)
    {
        inorder(rt->left);
        printf("%d\n", rt->info);
        inorder(rt->right);
    }
}
void count_leafnode(tree *rt, int *ct)
{
    if (rt != NULL)
    {
        if (rt->left == NULL && rt->right == NULL)
        {
            (*ct)++;
        }
        else
        {
            count_leafnode(rt->left, ct);
            count_leafnode(rt->right, ct);
        }
    }
}