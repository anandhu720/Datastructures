#include <stdio.h>
#include <stdlib.h>

//structure of queue
struct queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

//creating a queue with array
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

//inserting elements to a queue
void enqueue(struct queue *q, int x)
{
    if (q->rear == q->size - 1)
        printf("queue overflow!!!!!!\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = x;
    }
}

//deleting an element from a queue
int dequeue(struct queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("queue underflow!!!\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

//displaying elements in a queue
void display(struct queue q)
{
    for (int i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}

int main()
{
    struct queue q;
    create(&q, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d\n", dequeue(&q));

    display(q);

    return 0;
}