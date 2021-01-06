#include <stdio.h>

class node
{
public:
    node *leftchild;
    int data;
    node *rightchild;
};

class queue
{
private:
    int size;
    int front;
    int rear;
    node **Q;

public:
    //creating a queue by using array
    queue()
    {
        size = 10;
        front = rear = -1;
        Q = new node *[size];
    }

    queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new node *[this->size];
    }

    void enqueue(node *x);
    void display();
    node *dequeue();
    int isEmpty() { return front == rear; }
};

void queue::enqueue(node *x)
{
    if (rear == size - 1)
        printf("queue overflow!!!!!!\n");
    else
    {
        rear++;
        Q[rear] = x;
    }
}

node *queue::dequeue()
{
    node *x = NULL;
    if (front == rear)
        printf("queue underflow!!!!!!\n");
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}