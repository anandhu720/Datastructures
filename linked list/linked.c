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

int main()
{
    int a[]={2,3,4,5,6};
    create(a,5);
    reversedisplay(head);
    printf("\n");
    return 0;
}