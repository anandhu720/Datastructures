#include <stdio.h>
#include <stdlib.h>

//structure of avl tree
struct tnode
{
    struct tnode *leftchild;
    int data;
    int height;
    struct tnode *rightchild;
} *root = NULL;

struct tnode *rinsert(struct tnode *p, int key)
{
    struct tnode *t;
    if (p == NULL)
    {
        t = (struct tnode *)malloc(sizeof(struct tnode));
        t->data = key;
        t->leftchild = t->rightchild = NULL;
        return t;
    }
    if (key < p->data)
        p->leftchild = rinsert(p->leftchild, key);
    else if (key > p->data)
        p->rightchild = rinsert(p->rightchild, key);

    return p;
}

void inorder(struct tnode *p)
{
    if (p)
    {
        inorder(p->leftchild);
        printf("%d ", p->data);
        inorder(p->rightchild);
    }
}

int main()
{
    root = rinsert(root, 30);
    rinsert(root, 10);
    rinsert(root, 50);
    rinsert(root, 15);

    inorder(root);
    printf("\n");

    return 0;
}