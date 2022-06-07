//  1. program to insert no in bst
//  2. inorede,preorder,postorder
// 3. count leaf nodes
// 4, count total nodes

#include <stdio.h>
#include <stdlib.h>
typedef struct treetype
{
    struct treetype *left;
    int info;
    struct treetype *right;
} tree;
void insert(tree **, int);
void inorder(tree *);
void preorder(tree *);
void postorder(tree *);
void count_leafnode(tree *, int *);
void count_nodes(tree *, int *);
int search_key(tree *, int);
int main()
{
    int ch = 0, x, key;
    tree *root = NULL;
    int count = 0, flag = 0;
    do
    {
        printf("\n1.Insert\n2.Display_Inorder\n3.Display_Preorder\n4.Display_Postorder\n5.count_leafnode\n6.Total nodes\n7.Searck_key\n8.Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the no you want to insert: ");
            scanf("%d", &x);
            insert(&root, x);
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
        case 5:
            count = 0;
            count_leafnode(root, &count);
            printf("Total leaf nodes are : %d", count);
            break;
        case 6:
            count_nodes(root, &count);
            printf("Total nodes are: %d", count);
            break;
        case 7:
            printf("Enter the key");
            scanf("%d", &key);
            flag = search_key(root, key);
            if (flag > 0)
            {
                printf("Element found.");
            }
            else
                printf("Elenent not found");
            break;

        case 8:
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
void count_leafnode(tree *rt, int *ct)
{
    if (rt != NULL)
    {
        if (rt->left == NULL && rt->right == NULL)
        {
            (*ct)++;
        }
        count_leafnode(rt->left, ct);
        count_leafnode(rt->right, ct);
    }
}
void count_nodes(tree *rt, int *ct)
{
    if (rt != NULL)
    {
        (*ct)++;
        count_nodes(rt->left, ct);
        count_nodes(rt->right, ct);
    }
}
int search_key(tree *rt, int key)
{
    int flag;
    if (rt != NULL)
    {
        if (rt->info == key)
        {
            flag = 1;
        }
        else
        {
            search_key(rt->left, key);
            search_key(rt->right, key);
        }
    }
}