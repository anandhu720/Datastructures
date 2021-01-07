#include <iostream>
#include <stdio.h>
#include "arrayqueuecpp.h"

class tree
{
public:
    node *root;
    tree() { root = NULL; }
    void createtree();
    void preorder(node *p);
    void postorder(node *p);
    void inorder(node *p);
    int height(node *p);
    int count(node *p);
    int count2(node *p);
    int sum(node *p);
};

//creating a tree
void tree::createtree()
{
    node *p, *t;
    int x;
    queue q(100);

    //entering root node
    printf("enter the value of root node\n");
    scanf("%d", &x);
    root = new node;
    root->data = x;
    root->leftchild = root->rightchild = NULL;
    q.enqueue(root);

    //entering left and right node
    while (!q.isEmpty())
    {
        p = q.dequeue();
        printf("enter the left child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->leftchild = t;
            q.enqueue(t);
        }
        printf("enter the right child of %d\n", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = new node;
            t->data = x;
            t->leftchild = t->rightchild = NULL;
            p->rightchild = t;
            q.enqueue(t);
        }
    }
}

//dispalying tree in various forms

void tree::preorder(node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        preorder(p->leftchild);
        preorder(p->rightchild);
    }
}

void tree::inorder(node *p)
{
    if (p != NULL)
    {
        inorder(p->leftchild);
        printf("%d ", p->data);
        inorder(p->rightchild);
    }
}

void tree::postorder(node *p)
{
    if (p != NULL)
    {
        postorder(p->leftchild);
        postorder(p->rightchild);
        printf("%d ", p->data);
    }
}

//finding height of a tree
int tree::height(node *p)
{
    int x = 0, y = 0;
    if (p == NULL)
        return 0;
    x = height(p->leftchild);
    y = height(p->rightchild);
    if (x > y)
        return x + 1;
    return y + 1;
}

//number of nodes in a tree
int tree::count(node *p)
{
    int x, y;
    if (p)
    {
        x = count(p->leftchild);
        y = count(p->rightchild);
        return x + y + 1;
    }
    return 0;
}

//number of nodes which have more than one nodes
int tree::count2(node *p)
{
    int x, y;
    if (p)
    {
        x = count2(p->leftchild);
        y = count2(p->rightchild);
        if (p->leftchild && p->rightchild)
            return x = y + 1;
        return x + y;
    }
    return 0;
}

int tree::sum(node *p)
{
    int x, y;
    if (p)
    {
        x = sum(p->leftchild);
        y = sum(p->rightchild);
        return x + y + p->data;
    }
    return 0;
}

int main()
{
    tree t;
    t.createtree();
    t.preorder(t.root);
    std::cout << "\n";
    std::cout << t.height(t.root) << "\n";
    return 0;
}