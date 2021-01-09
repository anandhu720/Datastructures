#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    struct tnode *leftchild;
    int data;
    struct tnode *rightchild;
};

struct tnode *root = NULL;

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
void insert(int key)
{
    struct tnode *t = root;
    struct tnode *r = NULL;
    struct tnode *p;
    if (root == NULL)
    {
        p = (struct tnode *)malloc(sizeof(struct tnode));
        p->data = key;
        p->leftchild = p->rightchild = NULL;
        root = p;
        return;
    }
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
    insert(30);
    insert(15);
    insert(50);

    inorder(root);
}