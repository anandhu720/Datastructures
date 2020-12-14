#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
};

class linkedlist
{
public:
    node *head = NULL;
    node *head2 = NULL;
    node *third = NULL;

    linkedlist() { head = NULL; }
    linkedlist(int a[], int n);
    // ~linkedlist();

    void display();
    void rdisplay(node *p);
    void reversedisplay(node *p);
    int node_count();
    int rnode_count(node *p);
    int sum();
    int rsum(node *p);
    int mult();
    int max();
    int rmax(node *p);
    int linear(int key);
    int rlinear(node *p, int key);
    int linear_move(int key); //doubt
    void insert(int index, int x);
    int delete_node(int index);
    int if_sorted();
    void delete_duplicates();
    void reverse_element();
    void reverse_link();
    void reverse_recursion(node *q, node *p);
    void concat();
    int merge();
    int if_loop();
};

linkedlist::linkedlist(int a[], int n)
{
    node *t, *last;
    head = new node;
    head->data = a[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new node;
        t->data = a[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

/*linkedlist::~linkedlist()
{
    node *p=head;
    while(head!=NULL)
    [
        head=head->next;
        delete p;
        p=head;
    ]
}*/

void linkedlist::display() //displaying linkedlist
{
    node *p = head;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void linkedlist::rdisplay(node *p) //display by recursion
{
    if (p != NULL)
    {
        cout << p->data << " ";
        rdisplay(p->next);
    }
}

void linkedlist::reversedisplay(node *p) //reverse display of linked list
{
    if (p != NULL)
    {
        reversedisplay(p->next);
        cout << p->data << " ";
    }
}

int linkedlist::node_count() //no.of nodes in linked list
{
    int count = 0;
    node *p = head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

int linkedlist::rnode_count(node *p) //no.of nodes by recursion
{
    if (p == NULL)
        return 0;
    return rnode_count(p->next) + 1;
}

int linkedlist::sum() //sum of elements in linked list
{
    node *p = head;
    int sum = 0;
    while (p != 0)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int linkedlist::rsum(node *p) //sum of elements using recursion
{
    if (p == NULL)
        return 0;
    return rsum(p->next) + p->data;
}

int linkedlist::mult() //product of elements in a linked list
{
    node *p = head;
    int muit = 1;
    while (p != NULL)
    {
        muit *= p->data;
        p = p->next;
    }
    return muit;
}

int linkedlist::max() //max element in linked list
{
    node *p = head;
    int num = -65536;
    while (p != NULL)
    {
        if (p->data > num)
            num = p->data;
        p = p->next;
    }
    return num;
}

int linkedlist::rmax(node *p) //max element by recursion
{
    int x;
    if (p == NULL)
        return 0;
    x = rmax(p->next);
    return x > p->data ? x : p->data;
}

int linkedlist::linear(int key) //linear search in linked list
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

int linkedlist::rlinear(node *p, int key) //linear search by recursion
{
    if (p == NULL)
        return 0;
    if (p->data == key)
        return p->data;
    return rlinear(p->next, key);
}

int linkedlist::linear_move(int key) //linear search and head movement
{
    node *p = head;
    node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p->data;
        }
        q = p;
        p = p->next;
    }
    return 0;
}

void linkedlist::insert(int index, int x) //inserting elements to an linked list
{
    node *p = head;
    node *t;
    t = new node;
    t->data = x;
    if (index < 0 || index > node_count())
        return;
    if (index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}

int linkedlist::delete_node(int index) //deleting elements from linked list
{
    node *p = head;
    node *q = NULL;
    int x = -1;

    if (index < 0 || index > node_count())
        return -1;
    if (index == 1)
    {
        q = head;
        x = head->data;
        head = head->next;
        delete q;
        return x;
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
        delete p;
        return x;
    }
}

int linkedlist::if_sorted() //checking if sorted (linked list)
{
    node *p = head;
    int x = -65536;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

void linkedlist::delete_duplicates() //deleting duplicates in linked list
{
    node *p = head;
    node *q = p->next;
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
            delete q;
            q = p->next;
        }
    }
}

//reversing linked list

void linkedlist::reverse_element() //reversing elements
{
    node *p = head;
    int *a, i;
    a = new int[node_count()];
    while (p != NULL)
    {
        a[i++] = p->data;
        p = p->next;
    }
    p = head;
    i--;
    while (p != NULL)
    {
        p->data = a[i--];
        p = p->next;
    }
}
void linkedlist::reverse_link() //reversing link
{
    node *p = head;
    node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    head = q;
}

void linkedlist::reverse_recursion(node *q, node *p) //rversing by recursion
{
    if (p != NULL)
    {
        reverse_recursion(p, p->next);
        p->next = q;
    }
    else
    {
        head = q;
    }
}

//operation of more than one linked list

void linkedlist::concat() //concatinating linked list
{
    node *p = head;
    node *q = head2;
    third = p;
    while (p != NULL)
        p = p->next;
    p->next;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    linkedlist l(a, 5);

    l.display();

    cout << "\n";
    return 0;
}