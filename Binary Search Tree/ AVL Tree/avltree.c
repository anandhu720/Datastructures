#include <stdio.h>
#include <stdlib.h>

//structure of avl tree
struct tnode
{
    struct tnode *leftchild;
    int data;
    int height;
    struct tnode *rightchild;
} *root = NULL;

int nodeheight(struct tnode *p) //finding node height
{
    int hl, hr;
    hl = (p && p->leftchild) ? p->leftchild->height : 0;
    hr = (p && p->rightchild) ? p->rightchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

//function for finding balanace factor
int balancefactor(struct tnode *p)
{
    int hl, hr;
    hl = (p && p->leftchild) ? p->leftchild->height : 0;
    hr = (p && p->rightchild) ? p->rightchild->height : 0;

    return hl - hr;
}

//ll rotation function
struct tnode *llrotation(struct tnode *p)
{
    struct tnode *pl = p->leftchild;
    struct tnode *plr = pl->rightchild;

    pl->rightchild = p;
    p->leftchild = plr;
    //changing height of p and pl
    p->height = nodeheight(p);
    pl->height = nodeheight(pl);

    if (root = p)
        root = pl; //pl is the new node if p is old one

    return pl;
}

//lr rotation function
struct tnode *lrrotation(struct tnode *p)
{
    struct tnode *pl = p->leftchild;
    struct tnode *plr = pl->rightchild;

    pl->rightchild = plr->leftchild;
    p->leftchild = plr->rightchild;

    plr->leftchild = pl;
    plr->rightchild = p;

    pl->height = nodeheight(pl);
    p->height = nodeheight(p);
    plr->height = nodeheight(plr);

    if (root == p)
        root = plr;

    return plr;
}

//rr rotation function
struct tnode *rrrotation(struct tnode *p)
{
    struct tnode *pl = p->rightchild;
    struct tnode *plr = pl->leftchild;

    pl->leftchild = p;
    p->rightchild = plr;
    //changing height of p and pl
    p->height = nodeheight(p);
    pl->height = nodeheight(pl);

    if (root = p)
        root = pl; //pl is the new node if p is old one

    return pl;
}
//rl rotation function
struct tnode *rlrotation(struct tnode *p)
{
    struct tnode *pl = p->rightchild;
    struct tnode *plr = pl->leftchild;

    pl->leftchild = plr->rightchild;
    p->rightchild = plr->leftchild;

    plr->rightchild = pl;
    plr->leftchild = p;

    pl->height = nodeheight(pl);
    p->height = nodeheight(p);
    plr->height = nodeheight(plr);

    if (root == p)
        root = plr;

    return plr;
}

//recursive insertion in avl trees
struct tnode *rinsert(struct tnode *p, int key)
{
    struct tnode *t;
    if (p == NULL)
    {
        t = (struct tnode *)malloc(sizeof(struct tnode));
        t->data = key;
        t->height = 1;
        t->leftchild = t->rightchild = NULL;
        return t;
    }
    if (key < p->data)
        p->leftchild = rinsert(p->leftchild, key);
    else if (key > p->data)
        p->rightchild = rinsert(p->rightchild, key);

    p->height = nodeheight(p); //function calling for finding height of a node

    if (balancefactor(p) == 2 && balancefactor(p->leftchild) == 1)
    { //ll rotation condition above line
        return llrotation(p);
    }
    else if (balancefactor(p) == 2 && balancefactor(p->leftchild) == -1)
    { //lr rotation condition
        return lrrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rightchild) == -1)
    { //rr rotation condition
        return rrrotation(p);
    }
    else if (balancefactor(p) == -2 && balancefactor(p->rightchild) == 1)
    { //rl rotation condition
        return rlrotation(p);
    }

    return p;
}

//inorder traversing
void inorder(struct tnode *p)
{
    if (p)
    {
        inorder(p->leftchild);
        printf("%d ", p->data);
        inorder(p->rightchild);
    }
}

int main()
{
    root = rinsert(root, 10);
    rinsert(root, 5);
    rinsert(root, 2);

    printf("\n");

    return 0;
}