#include <stdio.h>
#include <stdlib.h>
#include "linkedqueue.h"

struct tnode *root = NULL;

//creating tree structure
void tree_create()
{
    struct tnode *p, *t;
    int x;

    //entering root node
    printf("enter the value of root node\n");
    scanf("%d", &x);
    root = (struct tnode *)malloc(sizeof(struct tnode));
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    enqueue(root);

    //entering lef and right nodes
    while (isEmpty() != 1)
    {
        p = dequeue();
        printf("enter the left child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct tnode *)malloc(sizeof(struct tnode));
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            enqueue(t);
        }
        printf("enter the right child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct tnode *)malloc(sizeof(struct tnode));
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            enqueue(t);
        }
    }
}

//displaying tree using preorder
void preorder(struct tnode *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->leftchild);
        preorder(p->rightchild);
    }
}

//displaying tree using inorder
void inorder(struct tnode *p)
{
    if (p != NULL)
    {
        inorder(p->leftchild);
        printf("%d ", p->data);
        inorder(p->rightchild);
    }
}

//displaying tree using postorder
void postorder(struct tnode *p)
{
    if (p != NULL)
    {
        postorder(p->leftchild);
        postorder(p->rightchild);
        printf("%d ", p->data);
    }
}

int main()
{
    tree_create();
    preorder(root);
    return 0;
}