#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

struct tnode *root = NULL;

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