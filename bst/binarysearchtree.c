#include <stdio.h>
#include <stdlib.h>
#include "q.h"

struct tnode *root = NULL;

//creating binary search tree
void create_bst()
{
    struct tnode *p, *t;
    int x;

    //entering root nodes
    printf("enter the value of root node\n");
    scanf("%d", &x);
    root = (struct tnode *)malloc(sizeof(struct tnode));
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    enqueue(root);

    //entering left and right nodes
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

//searching binary search tree
struct tnode *rsearch(struct tnode *t, int key) //using recursion
{
    if (t == NULL)
        return NULL;
    if (key == t->data)
        return t;
    else if (key < t->data)
        return rsearch(t->leftchild, key);
    return rsearch(t->rightchild, key);
}

//inserting to a binary search tree
void insert(struct tnode *t, int key)
{
    struct tnode *r = NULL;
    struct tnode *p;
    while (t != NULL)
    {
        r = t;
        if (key == t->data)
            return;
        else if (key < t->data)
            t = t->leftchild;
        else
            t = t->rightchild;
    }
    p = (struct tnode *)malloc(sizeof(struct tnode));
    p->data = key;
    p->leftchild = p->rightchild = NULL;
    if (key < r->data)
        r->leftchild = p;
    else
        r->rightchild = p;
}

//viewing tree in inorder
void inorder(struct tnode *t)
{
    if (t != NULL)
    {
        inorder(t->leftchild);
        printf("%d ", t->data);
        inorder(t->rightchild);
    }
}

int main()
{
    create_bst();
    insert(root, 32);
    inorder(root);
}