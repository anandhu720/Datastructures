//dobly linkedlist code

#include <iostream>
using namespace std;

class node
{
public:
    node *prev;
    int data;
    node *next;
};

class dlinkedlist
{
public:
    node *head;

    dlinkedlist() { head = NULL; }
    dlinkedlist(int a[], int n);
    //~dlinkedlist();

    void display();
    void rdisplay(node *p);
    void reversedisplay(node *p);
    int node_count();
    int rnode_count(node *p);
    int sum();
    int rsum(node *p);
    int multi();
    int max();
    int rmax(node *p);
    int linear(int key);
    int rlinear(node *p, int key);
    void insert(int index, int x);
    int delete_node(int index);
    int ifsorted();
    void delete_duplicate();
    void reverse();
};

//creating a doubly linked list
dlinkedlist::dlinkedlist(int a[], int n)
{
    node *t, *last;
    head = new node;
    head->data = a[0];
    head->next = NULL;
    head->prev = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        t->prev = last;
        last = t;
    }
}

//displaying a doubly linked list
void dlinkedlist::display()
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

//displaying a doubly linked list by recursive
void dlinkedlist::rdisplay(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        rdisplay(p->next);
    }
}

//displaying a doubly linked list in reverse by recursive function
void dlinkedlist::reversedisplay(node *p)
{
    if (p != NULL)
    {
        reversedisplay(p->next);
        printf("%d ", p->data);
    }
}

//lenght of a doubly linked list
int dlinkedlist::node_count()
{
    node *p = head;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

//lenght of a doubly linked list by recursive function
int dlinkedlist::rnode_count(node *p)
{
    if (p == NULL)
        return 0;
    return rnode_count(p->next) + 1;
}

//sum of a doubly linked list elements
int dlinkedlist::sum()
{
    node *p = head;
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

//sum of a doubly linked list elements by recursive function
int dlinkedlist::rsum(node *p)
{
    if (p == NULL)
        return 0;
    return rsum(p->next) + p->data;
}

//multi of a doubly linked list
int dlinkedlist::multi()
{
    int multi = 1;
    node *p = head;
    while (p != NULL)
    {
        multi *= p->data;
        p = p->next;
    }
    return multi;
}

//max element of a doubly linked list
int dlinkedlist::max()
{
    node *p = head;
    int max = -65536;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}

//max element of a doubly linked list by recursive function
int dlinkedlist::rmax(node *p)
{
    int x;
    if (p == NULL)
        return 0;
    x = rmax(p->next);
    return x > p->data ? x : p->data;
}

//linear search of doubly linked list
int dlinkedlist::linear(int key)
{
    node *p = head;
    while (p != NULL)
    {
        if (p->data == key)
            return p->data;
        p = p->next;
    }
    return 0;
}

//linear search of a doubly linked list by recursive function
int dlinkedlist::rlinear(node *p, int key)
{
    if (p == NULL)
        return 0;
    if (p->data == key)
        return p->data;
    return rlinear(p->next, key);
}

//insert function into doubly linked list
void dlinkedlist::insert(int index, int x)
{
    node *p = head;
    node *t;
    t = new node;
    if (index < 0 || index > node_count())
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

//delete element from doubly linked list
int dlinkedlist::delete_node(int index)
{
    node *p = head;
    int x = -1;
    if (index < 1 || index > node_count())
        return -1;
    if (index == 1)
    {
        head = head->next;
        if (head)
            head->prev = NULL;
        x = p->data;
        delete p;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next != NULL)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

//checking if doubly linked list sorted
int dlinkedlist::ifsorted()
{
    node *p = head;
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0; //false
        x = p->data;
        p = p->next;
    }
    return 1; //true
}

//deleting duplicates from doubly linked list
void dlinkedlist::delete_duplicate()
{
    node *p = head;
    node *q = p->next;
    while (q != NULL)
    {
        if (q->data != p->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

//.....bug................................................................
void dlinkedlist::reverse()
{
    node *p = head;
    node *t;
    while (p != head)
    {
        t = p->next;
        p->next = p->prev;
        p->prev = t;
        p = p->prev;
        if (p->next != NULL && p != NULL)
            head = p;
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    dlinkedlist d(a, 5);

    d.reverse();

    d.display();
    cout << "\n";
    return 0;
}
