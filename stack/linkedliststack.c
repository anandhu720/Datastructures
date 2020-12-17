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

//main function
int main()
{
    push(10);
    push(20);
    push(30);
    push(40);

    display();
    printf("\n");
    return 0;
}