#include <stdio.h>
#include <stdlib.h>

//tree node
struct tnode
{
    struct tnode *leftchild;
    int data;
    struct tnode *rightchild;
};

//queue node
struct qnode
{
    struct tnode *data; //
    struct qnode *next;
} *first = NULL, *rear = NULL;

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
        if (first == NULL)
            first = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

struct tnode *dequeue()
{
    struct tnode *x = NULL;
    struct qnode *p;
    if (first == NULL)
        printf("queue underflow!!!!!!\n");
    else
    {
        x = first->data;
        p = first;
        first = first->next;
        free(p);
    }
    return x;
}

int isEmpty()
{
    if (first == NULL)
        return 1;
}