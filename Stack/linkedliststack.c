#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *top = NULL;

//inserting element in stack by using linkedlist
void push(int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("stack overflow!!!!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

//deleting element in stack by using linkedlist
int pop()
{
    int x = -1;
    struct node *t;
    if (top == NULL)
        printf("stack is empty!!!\n");
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

//displaying element in stack by using linkedlist
void display()
{
    struct node *t;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

//getting and element from stack by using linkedlist
int peek(int index)
{
    struct node *p = top;
    for (int i = 0; p != NULL && i < index - 1; i++)
        p = p->next;
    if (p != NULL)
        return p->data;
    return -1;
}

//last element in stack by using linkedlist
int stacktop()
{
    if (top != NULL)
        return top->data;
    else
        return -1;
}

//checking if stack is full
int iffull()
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    int r = p != NULL ? 0 : 1;
    free(p);
    return r;
}

//checking if stack is zero
int ifempty()
{
    if (top == NULL)
        return 1;
    return 0;
}

//main function
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    display();

    printf("\n%d", peek(3));
    printf("\n");
    return 0;
}