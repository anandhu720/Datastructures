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

int main()
{
    int a[]={2,3,4,5,6,3,4};
    create(a,7);
    printf("the lenght of linked list is %d",rsum(head));
    printf("\n");
    return 0;
}