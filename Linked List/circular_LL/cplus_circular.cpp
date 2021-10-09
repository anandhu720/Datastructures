#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class circular
{
public:
    node *head;

    circular() { head = NULL; }
    circular(int a[], int n);
    void display();
    void rdisplay(node *p);
    int lenght();
    void insert(int index, int x);
    int delete_node(int index);
};

circular::circular(int a[], int n)
{
    node *p = head;
    int i;
    node *t, *last;
    head = new node;
    head->data = a[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void circular::display()
{
    node *p = head;
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}
