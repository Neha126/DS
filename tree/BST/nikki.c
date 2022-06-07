#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    struct node *left;
    int info;
    struct node *right;
} treetype;
void insert(treetype **, int);
void inorder(treetype *);
void preorder(treetype *);
void postorder(treetype *);
void count_node(treetype *, int *);
int search_key(treetype *, int);
void count_leafnode(treetype *, int *);

void main()
{
    treetype *root = NULL;
    int x, ch, count = 0, flag = 0;
    do
    {
        printf("Enter your choice:\n1-insert\n2-Inorder\n3-Preorder\n4-Postorder\n5-Count Total Nodes\n6-Search Element\n7-Count Leaf Nodes\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value to be inserted\n");
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
            count_node(root, &count);
            printf("Total No of nodes is: %d\n", count);
            break;
        case 6:
            printf("Enter key to be searched\n");
            scanf("%d", &x);
            flag = search_key(root, x);
            if (flag > 0)
            {
                printf("Element found\n");
            }
            else
            {
                printf("Element not found\n");
            }
            break;
        case 7:
            count = 0;
            count_leafnode(root, &count);
            printf("Total no of Leaf Nodes is:%d\n", count);
            break;
        }
    } while (ch <= 7);
} // end of main()
void insert(treetype **root, int x)
{
    treetype *p = NULL;
    if ((*root) == NULL)
    {
        p = (treetype *)malloc(sizeof(treetype));
        if (p != NULL)
        {
            p->info = x;
            p->left = NULL;
            p->right = NULL;
            *root = p;
            return;
        }
    }

    else
    {

        if (x < (*root)->info)
        {
            insert((&(*root)->left), x);
        }
        else
        {
            insert((&(*root)->right), x);
        }
    }
}
void inorder(treetype *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\n", root->info);
        inorder(root->right);
    }
}
void preorder(treetype *root)
{
    if (root != NULL)
    {
        printf("%d\n", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(treetype *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d\n", root->info);
    }
}

void count_node(treetype *root, int *count)
{
    if (root != NULL)
    {
        (*count)++;
        count_node(root->left, count);
        count_node(root->right, count);
    }
}
int search_key(treetype *root, int key)
{
    static int flag;
    if (root != NULL)
    {
        if (root->info == key)
        {
            flag = 1;
        }
        else
        {
            search_key(root->left, key);
            search_key(root->right, key);
        }
    }
    return (flag);
}
void count_leafnode(treetype *root, int *count)
{
    if (root != NULL)
    {
        if (root->left == NULL && root->right == NULL)
        {
            (*count)++;
        }
        count_leafnode(root->left, count);
        count_leafnode(root->right, count);
    }
}