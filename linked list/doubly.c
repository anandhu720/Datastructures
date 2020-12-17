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
    head->prev = NULL;
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = a[i];
        t->next = NULL;
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

//displaying doubly linked list by recursion
void rdisplay(struct node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

//displaying doubly linked list reverse by recursion
void rrevrsedisplay(struct node *p)
{
    if (p != NULL)
    {
        rrevrsedisplay(p->next);
        printf("%d ", p->data);
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

//lenghtof doubly linked list by recursion
int rnode_count(struct node *p)
{
    if (p == NULL)
        return 0;
    return rnode_count(p->next) + 1;
}

//sum of all nodes in doubly linked list
int sum(struct node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count += p->data;
        p = p->next;
    }
    return count;
}

//sum of all nodes in doubly linked list by recursion
int rsum(struct node *p)
{
    if (p == NULL)
        return 0;
    return rsum(p->next) + p->data;
}

//multi of elements in doubly linked list
int multi(struct node *p)
{
    int ans = 1;
    while (p != NULL)
    {
        ans *= p->data;
        p = p->next;
    }
    return ans;
}

//max element in doubly linked list
int max(struct node *p)
{
    int max = -65536;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

//max element in doubly linked list by recursion
int rmax(struct node *p)
{
    int x;
    if (p == NULL)
        return 0;
    x = rmax(p->next);
    return x > p->data ? x : p->data;
}

//linear search in doubly linked list
struct node *linearsearch(struct node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}

//linear search in doubly linked list by recursion
struct node *rlinearsearch(struct node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return rlinearsearch(p->next, key);
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

//delete element doubly linked list
int delete_nodes(struct node *p, int index)
{
    int x = -1;
    if (index < 1 || index > node_count(head))
    {
        return -1;
    }

    if (index == 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        x = p->data;
        free(p);
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

//checking if doubly linked list is sorted
int if_sorted(struct node *p)
{

    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0; //means that False(unsorted)
        x = p->data;
        p = p->next;
    }
    return 1; //1 means True(sorted)
}

//deleting duplicates in doubly linked list
void deletingduplicates(struct node *p)
{
    struct node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

//reversing a dobly linked list
void reverse(struct node *p) //segamentation core dump
{
    struct node *t;
    while (p != NULL)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p->next == NULL && p != NULL)
        {
            head = p;
        }
    }
}

//main function
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    create(a, 5);

    reverse(head);
    display(head);
    printf("\n");
    return 0;
}