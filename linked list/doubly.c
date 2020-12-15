#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;

//creating doubly linked list
void create(int a[], int n)
{
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->prev = head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

//displaying a doubly linked list
void display(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

//length of doubly linked list
int node_count(struct node *p)
{
    int length = 0;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    return length;
}

//insert function in doubly linked list
void insert(struct node *p, int index, int x)
{
    struct node *t;
    t = (struct node *)malloc(sizeof(struct node));
    if (index < 0 || index > node_count(head))
        return;
    if (index == 0)
    {
        t->data = x;
        t->next = head;
        t->prev = NULL;
        head->prev = t;
        head = t;
    }
    else
    {
        t->data = x;
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next != NULL)
            p->next->prev = t;
        p->next = t;
    }
}

//max elelment doubly linked list
int max(struct node *p)
{
    int x = -65536;
    while (p != NULL)
    {
        if (p->data > x)
            x = p->data;
        p = p->next;
    }
    return x;
}

//main function
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);
    insert(head, 2, 32);

    //printf("the lenght is %d\n", node_count(head));

    display(head);
    printf("\n");
    return 0;
}