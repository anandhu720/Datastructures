#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *leftchild;
    int data;
    struct node *rightchild;
};

struct queue
{
    int size;
    int front;
    int rear;
    struct node **Q;
};

void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = (struct node **)malloc(size * sizeof(struct node *));
}

void enqueue(struct queue *q, struct node *x)
{
    if (q->front == (q->rear + 1) % q->size)
        printf("queue overflow!!!!!!\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

struct node *dequeue(struct queue *q)
{
    struct node *x = NULL;
    if (q->front == q->rear)
        printf("queue underflow!!!\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int isEmpty(struct queue q)
{
    return q.front == q.rear;
}