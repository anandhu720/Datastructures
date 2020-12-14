#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int a[], int n) //creating circular linked list
{
    int i;
    struct node *t, *last;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = a[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct node *p) //displaying circular linked list
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

void rdisplay(struct node *p) //display by recursion
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag++;
        printf("%d ", p->data);
        rdisplay(p->next);
    }
    flag = 0;
}

int lenght(struct node *p) //lenght of linked list
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}

void insert(struct node *p, int index, int x) //inserting to circular linkedlist
{
    struct node *t;
    int i;
    if (index < 0 || index > lenght(head))
        return;
    if (index == 0)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t = (struct node *)malloc(sizeof(struct node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int delete_node(struct node *p, int index) //deleting node from linked list
{
    int x;
    struct node *q = NULL;
    if (index < 0 || index > lenght(head))
        return -1;
    if (index == 1)
    {
        while (p->next != head)
            p = p->next;
        x = head->data;
        if (p == head)
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
    }
    return x;
}
/* code */
int main()
{
    int a[] = {2, 4, 6, 8, 10};
    create(a, 5);
    delete_node(head, 1);

    rdisplay(head);
    return 0;
}