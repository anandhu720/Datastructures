#include <stdio.h>
#include <stdlib.h>

//structure for node used in linked linkedlist
struct node
{
    int data;
    struct node *next;
} *frist = NULL, *rear = NULL;

//inserting element into a queue using linkedlist
void enqueue(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("queue overflow!!!!!!\n");
    else
    {
        t->data = x;
        t->next = NULL;
        if (frist == NULL)
        {
            frist = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

//deleting element from queue using linked list
int dequeue()
{
    int x = -1;
    struct node *p;
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

//displaying queue
void display()
{
    struct node *p = frist;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//main function
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    printf("%d\n", dequeue());
    display();

    return 0;
}