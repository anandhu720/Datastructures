#include <iostream>
using namespace std;

//class for linked list
class node
{
public:
    int data;
    node *next;
};

//class of stack
class stack
{
private:
    node *top;

public:
    stack() { top = NULL; }
    void push(int x);
    int pop();
    void display();
    int peek(int index);
};

//inserting element to stack
void stack::push(int x)
{
    node *t = new node;
    if (t == NULL)
        printf("stack overflow!!!!!!\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

//deleting element from stack
int stack::pop()
{
    int x = -1;
    node *t = top;
    if (top == NULL)
        printf("stack underflow!!!!!!!\n");
    else
    {
        top = t->next;
        x = t->data;
        delete t;
    }
    return x;
}

//dispaying element from stack
void stack::display()
{
    node *t = top;
    while (t != NULL)
    {
        printf("%d ", t->data);
        t = t->next;
    }
}

//getting element at a given index in stack
int stack::peek(int index)
{
    node *t = top;
    for (int i = 0; i < index - 1 && t != NULL; i++)
        t = t->next;
    if (t != NULL)
        return t->data;
    return -1;
}

//main function
int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.peek(1) << "\n";
    s.display();
    printf("\n");
    return 0;
}