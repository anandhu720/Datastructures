#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}*head=NULL;

//creating linked list
void create(int a[],int n)
{
    struct node *t,*last;
    head=(struct node *)malloc(sizeof(struct node));
    head->data=a[0];
    head->next=NULL;
    last=head;

    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node));
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}


//displaying linked list by loop
void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}

//displaying linked list by recursion
void rdisplay(struct node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        rdisplay(p->next);
    }
}

//displaying linked list in reverse by recursion
void reversedisplay(struct node *p)
{
    if(p!=NULL)
    {
        reversedisplay(p->next);
        printf("%d ",p->data);
    }
}

//counting nodes
int node_count(struct node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
    }
    return count;
}

//counting nodes by recursion
int rnode_count(struct node *p)
{
    if(p==NULL)
        return 0;
    return rnode_count(p->next)+1;
}

//sum of elements in a linked list
int sum(struct node *p)
{
    int sum=0;
    while(p!=NULL)
    {
        sum+=p->data;
        p=p->next;
    }
    return sum;
}

//sum of elements using recursion
int rsum(struct node *p)
{
    if (p==0)
        return 0;
    return rsum(p->next)+p->data;
}

//mult of elements 
int mult(struct node *p)
{
    int mult=1;
    while(p!=NULL)
    {
        mult*=p->data;
        p=p->next;
    }
    return mult;
}

//max element in linked list
int max(struct node *p)
{
    int max=-3845;
    while(p!=NULL)
    {
        if(p->data > max)
            max=p->data;
        p=p->next;
    }
    return max;
}

//max element by recursion
int rmax(struct node *p)
{
    int x;

    if(p==NULL)
        return 0;
    x=max(p->next);
    return x>p->data?x:p->data;
}

//linear search in linked list
struct node * linear(struct node *p,int key)
{
    while(p!=NULL)
    {
        if(p->data==key)
            return p;
        p=p->next;
    }
    return NULL;
}

//linear search by recursion
struct node * rlinear(struct node *p,int key)
{
    if(p==NULL)
        return NULL;
    if(p->data==key)
        return p;
    return rlinear(p->next,key);
}

//linear search by moving head
struct node * linear_move(struct node *p,int key)
{
    struct node *q=NULL;
    while (p!=NULL)
    {
        if(p->data==key)
        {
            q->next=p->next;
            p->next=head;
            head=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}

void insert(struct node *p,int index,int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=x;
    if( index < 0 || index > node_count(p))
        return;
    if (index == 0)
    {
        t->next=head;
        head=t;
    }
    else 
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
    
}


//deleting an element
int delete_node(struct node *p,int index)
{
    struct node *q=NULL;
    int x=-1;

    if (index < 1 || index > node_count(p))
        return -1;
    if(index == 1)
    {
        q=head;
        x=head->data;
        head=head->next;
        free (q);
        return x;
    }
    else
    {
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free (p);
        return x;
    }
    
}

int main()
{
    struct node *t;
    int a[]={20,30,14,23,1};
    create(a,5);
    delete_node(head,1);
/* t=linear_move(head,6);
    if(t!=NULL)
        printf("the element is found %d",t->data);
    else 
        printf("element is not found");
    printf("\n"); */
    display(head);
    printf("\n");
    return 0;
}