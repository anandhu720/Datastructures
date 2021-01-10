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

//finding height of a tree
int height(struct tnode *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
    x = height(p->leftchild);
    y = height(p->rightchild);
    if (x > y)
        return x + 1;
    return y + 1;
}

//finding predicesser
struct tnode *inpre(struct tnode *p)
{
    while (p && p->rightchild != NULL)
    {
        p = p->rightchild;
    }
    return p;
}

//finding succserr
struct tnode *insucc(struct tnode *p)
{
    while (p && p->leftchild != NULL)
    {
        p = p->leftchild;
    }
    return p;
}

//deleting functions

///bug.....................................................................
struct tnode *delete_node(struct tnode *p, int key)
{
    struct tnode *q;
    if (p == NULL)
        return NULL;
    if (p->leftchild == NULL && p->rightchild == NULL)
    {
        if (p == root)
            root = NULL;
        free(p);
        return NULL;
    }
    if (key < p->data)
        p->leftchild = delete_node(p->leftchild, key);
    else if (key > p->data)
        p->rightchild = delete_node(p->rightchild, key);
    else
    {
        if (height(p->leftchild) > height(p->rightchild))
        {
            q = inpre(p->leftchild);
            p->data = q->data;
            p->leftchild = delete_node(p->leftchild, q->data);
        }
        else
        {
            q = insucc(p->rightchild);
            p->data = q->data;
            p->rightchild = delete_node(p->rightchild, q->data);
        }
        return p;
    }
}

int main()
{
    insert(50);
    insert(10);
    insert(40);
    insert(20);
    insert(30);

    delete_node(root, 50);

    inorder(root);
}