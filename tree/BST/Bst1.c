#include <stdio.h>
#include <stdlib.h>
typedef struct nodetype
{
    struct nodetype *left;
    int info;
    struct nodetype *right;
} tree;
void insert(tree **, int);
void inorder(tree *);
void node_count(tree *, int *);
int main()
{
    int ch = 0, no;
    tree *root = NULL;
    int count = 0;

    do
    {
        printf("\n1.Insert\n2.Count node\n3.inorder\n4.exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no\n");
            scanf("%d", &no);
            insert(&root, no);
            break;
        case 2:
            node_count(root, &count);
            printf("%d", count);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            return (0);
        }
    } while (ch != 0);
}
void insert(tree **rt, int no)
{
    tree *newNode;
    if ((*rt) == NULL)
    {
        newNode = (tree *)malloc(sizeof(tree));
        newNode->info = no;
        newNode->left = NULL;
        newNode->right = NULL;
        *rt = newNode;
    }
    else
    {
        if (no < (*rt)->info)
            insert(&((*rt)->left), no);
        else
        {
            insert(&((*rt)->right), no);
        }
    }
}

void node_count(tree *rot, int *ct)
{
    if (rot != NULL)
    {
        (*ct)++;

        node_count(rot->left, ct);
        node_count(rot->right, ct);
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