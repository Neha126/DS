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
void preorder(tree *);
void postorder(tree *);

int main()
{
    int ch = 0, no, x;
    tree *root = NULL;
    do
    {
        printf("\n1.insert\n2.inorder Display\n3.preorder Display\n4.postorder Display\n6.exit\n");
        scanf("\n%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the no\n");
            scanf("%d", &no);
            insert(&root, no);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;

        case 6:
            return (0);
            break;
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
void inorder(tree *rt)
{
    if (rt != NULL)
    {
        inorder(rt->left);

        printf("%d\n", rt->info);
        inorder(rt->right);
    }
}
void preorder(tree *rt)
{
    if (rt != NULL)
    {
        printf("%d\n", rt->info);
        preorder(rt->left);
        preorder(rt->right);
    }
}
void postorder(tree *rt)
{
    if (rt != NULL)
    {
        postorder(rt->left);
        postorder(rt->right);
        printf("%d\n", rt->info);
    }
}