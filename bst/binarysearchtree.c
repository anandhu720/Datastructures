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
struct tnode *rsearch(struct tnode *t, int key)
{
    if (t == NULL)
        return NULL;
    if (key == t->data)
        return t;
    else if (key < t->data)
        return rsearch(t->leftchild, key);
    return rsearch(t->rightchild, key);
}

int main()
{
    create_bst();
    long int x = (long int)rsearch(root, 15);
    printf("%ld\n", x);
}