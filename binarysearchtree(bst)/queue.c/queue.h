#include <stdio.h>
#include <stdlib.h>

//tree node
struct tnode
{
    int data;
    struct tnode *leftchild;
    struct node *rightchild;
};

//queue node
struct qnode
{
    struct tnode *data;
    struct qnode *next;
} *frist = NULL, *rear = NULL;

//entering to queue
void enqueue(struct tnode *x)
{
    struct qnode *t;
    t = (struct qnode *)malloc(sizeof(struct qnode));
    if (t == NULL)
        printf("queue overflow!!!!!!\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (frist == NULL)
            frist = rear = t;
        else
        {
            rear->next = t;
            t = rear;
        }
    }
}

//deleting element from queue
struct tnode *dequeue()
{
    struct tnode *x = NULL;
    struct qnode *p = NULL;
    if (frist == NULL)
        printf("queue underflow!!!!!!\n");
    else
    {
        x = frist->data;
        p = frist;
        frist = frist->next;
        free(p);
    }
    return x;
}

int isEmpty()
{
    if (frist == NULL)
        return 1;
}
