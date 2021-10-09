#include <iostream>
using namespace std;

class tnode
{
public:
    tnode *leftchild;
    int data;
    tnode *rightchild;
};

class bst
{
public:
    tnode *root = NULL;
    tnode *getroot() { return root; }
    tnode *rsearch(tnode *p, int key);
    void insert(int key);              //by loop
    tnode *rinsert(tnode *p, int key); //by recursion
    void inorder(tnode *p);
    int height(tnode *p);
    tnode *inpre(tnode *p);
    tnode *insucc(tnode *p);
    tnode *delete_node(tnode *p, int key);
};

//searchimg element in a bst by recursion
tnode *bst::rsearch(tnode *p, int key)
{
    if (p == nullptr)
        return nullptr;
    if (key == p->data)
        return p;
    else if (key < p->data)
        return rsearch(p->leftchild, key);
    else
        return rsearch(p->rightchild, key);
}

//inserting to bst by iterations
void bst::insert(int key)
{
    tnode *r = NULL; //tail pointer
    tnode *t = root;
    tnode *p;
    if (root == NULL) //creating root if root is emplty
    {
        p = new tnode;
        p->data = key;
        p->leftchild = p->rightchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t; //tail pointer used
        if (key == t->data)
            return;
        else if (key < t->data)
            t = t->leftchild;
        else
            t = t->rightchild;
    }
    p = new tnode;
    p->data = key;
    p->leftchild = p->rightchild = NULL;
    if (key < r->data)
        r->leftchild = p;
    else
        r->rightchild = p;
}

//inserting to bst by recursion
tnode *bst::rinsert(tnode *p, int key)
{
    tnode *t = NULL;
    if (p == NULL)
    {
        t = new tnode;
        t->data = key;
        t->leftchild = t->rightchild = NULL;
        return t;
    }
    if (key < p->data)
        p->leftchild = rinsert(p->leftchild, key);
    else if (key > p->data)
        p->rightchild = rinsert(p->rightchild, key);

    return p;
}

//inorder displaying of BST
void bst::inorder(tnode *p)
{
    if (p)
    {
        inorder(p->leftchild);
        cout << p->data << " " << flush;
        inorder(p->rightchild);
    }
}

//height of a bst
int bst::height(tnode *p)
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

//finding predicesser
tnode *bst::inpre(tnode *p)
{
    while (p && p->leftchild)
    {
        p = p->leftchild;
    }
    return p;
}

//finding sucsser of bst
tnode *bst::insucc(tnode *p)
{
    while (p && p->rightchild)
    {
        p = p->rightchild;
    }
    return p;
}

//deleting node from bst
tnode *bst::delete_node(tnode *p, int key)
{
    tnode *q;
    if (p == nullptr)
        return nullptr;
    if (p->leftchild == nullptr && p->rightchild == nullptr)
    {
        if (p == root)
            root = nullptr;
        delete p;
        return nullptr;
    }
    if (key < p->data)
        p->leftchild = delete_node(p->leftchild, key);
    else if (key > p->data)
        p->rightchild = delete_node(p->rightchild, key);
    else
    {
        if (height(p->leftchild) > height(p->rightchild))
        {
            q = inpre(p->leftchild);
            p->data = q->data;
            p->leftchild = delete_node(p->leftchild, q->data);
        }
        else
        {
            q = insucc(p->rightchild);
            p->data = q->data;
            p->rightchild = delete_node(p->rightchild, q->data);
        }
    }
    return p;
}

//main function
int main()
{
    bst tree;

    tree.root = tree.rinsert(tree.root, 30);
    tree.rinsert(tree.root, 15);
    tree.rinsert(tree.root, 50);
    tree.rinsert(tree.root, 10);
    tree.rinsert(tree.root, 60);
    tree.rinsert(tree.root, 20);
    tree.rinsert(tree.root, 40);

    tree.delete_node(tree.root, 30);

    tree.inorder(tree.root);

    return 0;
}